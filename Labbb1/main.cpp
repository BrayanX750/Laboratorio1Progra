#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Drone.h"
#include "Motorcycle.h"
#include "IFlyable.h"

int main() {
    std::vector<Vehicle*> fleet;

    fleet.push_back(new Car("Tesla Model 3"));
    fleet.push_back(new Truck("Ford F-150"));
    fleet.push_back(new Drone("DJI Mini 3"));
    fleet.push_back(new Motorcycle("Yamaha R6"));

    std::cout << "[0h] Initial Status" << std::endl;
    for (Vehicle* v : fleet) {
        std::cout << v->status() << std::endl;
    }
    std::cout << std::endl;

    for (int hour = 1; hour <= 8; ++hour) {
        for (Vehicle* v : fleet) {
            v->simulateHour();
        }

        if (hour % 2 == 0) {
            for (Vehicle* v : fleet) {
                IFlyable* f = dynamic_cast<IFlyable*>(v);
                if (f) {
                    f->fly();
                }
            }
        }

        if (hour % 3 == 0) {
            std::cout << "[" << hour << "h] Refueling all vehicles (+15)" << std::endl;
            for (Vehicle* v : fleet) {
                v->refuel(15);
            }
        }

        std::cout << "[" << hour << "h]" << std::endl;
        for (Vehicle* v : fleet) {
            std::cout << v->status() << std::endl;
        }
        std::cout << std::endl;
    }

    // 🔹 Final summary
    std::cout << "========== FINAL SUMMARY ==========" << std::endl;
    for (Vehicle* v : fleet) {
        std::cout << v->status() << std::endl;
    }
    std::cout << "===================================" << std::endl;

    for (Vehicle* v : fleet) {
        delete v;
    }

    fleet.clear();
    return 0;
}
