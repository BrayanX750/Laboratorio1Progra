#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Drone.h"
#include "Motorcycle.h"

int main() {
    std::vector<Vehicle*> fleet;

    fleet.push_back(new Car("Tesla Model 3"));
    fleet.push_back(new Truck("Ford F-150"));
    fleet.push_back(new Drone("DJI Mini 3"));
    fleet.push_back(new Motorcycle("Yamaha R6"));


    for (int hour = 0; hour <= 7; ++hour) {


        for (Vehicle* v : fleet) {
            v->simulateHour();
        }


        std::cout << "[" << hour << "h]" << std::endl;


        for (Vehicle* v : fleet) {
            std::string typeStatus = v->status();
            std::cout << typeStatus << std::endl;


            Drone* dronePtr = dynamic_cast<Drone*>(v);
            if (dronePtr && (hour == 2 || hour == 4 || hour == 6)) {
                std::cout << "Attempting flight for flyable vehicles..." << std::endl;
                dronePtr->fly();
            }
        }


        if (hour == 3 || hour == 6) {
            std::cout << "Refueling all vehicles (+15)" << std::endl;
            for (Vehicle* v : fleet) {
                v->refuel(15);
            }
        }

        std::cout << std::endl;
    }


    std::cout << "FINAL SUMMARY: " << std::endl;
    for (Vehicle* v : fleet) {
        Drone* dronePtr = dynamic_cast<Drone*>(v);
        if (dronePtr) {
            std::cout << "- " << v->getName() << " -> Battery: "
                      << v->getFuelLevel() << std::endl;
        } else {
            std::cout << "- " << v->getName() << " -> Fuel Level: "
                      << v->getFuelLevel() << std::endl;
        }
    }



    for (Vehicle* v : fleet) {
        delete v;
    }
    fleet.clear();

    return 0;
}
