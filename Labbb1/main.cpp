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

    // Simulación de 8 horas reales: 0,1,2,3,4,5,6,7
    for (int hour = 0; hour <= 7; ++hour) {


        for (Vehicle* v : fleet) {
            v->simulateHour();
        }

        // 2️⃣ Encabezado de hora
        std::cout << "[" << hour << "h]" << std::endl;

        // 3️⃣ Imprimir estado pero con vuelo debajo del Drone
        for (Vehicle* v : fleet) {
            std::string typeStatus = v->status();
            std::cout << typeStatus << std::endl;


            Drone* dronePtr = dynamic_cast<Drone*>(v);
            if (dronePtr && (hour == 2 || hour == 4 || hour == 6)) {
                std::cout << "Attempting flight for flyable vehicles..." << std::endl;
                dronePtr->fly(); // imprime "<name> flew for 5 minutes."
            }
        }

        // 4️⃣ Refuel SOLO en 3h y 6h
        if (hour == 3 || hour == 6) {
            std::cout << "Refueling all vehicles (+15)" << std::endl;
            for (Vehicle* v : fleet) {
                v->refuel(15);
            }
        }

        std::cout << std::endl;
    }

    // 5️⃣ Final summary
    std::cout << "========== FINAL SUMMARY ==========" << std::endl;
    for (Vehicle* v : fleet) {
        std::cout << v->status() << std::endl;
    }
    std::cout << "===================================" << std::endl;

    // 6️⃣ Liberar memoria
    for (Vehicle* v : fleet) {
        delete v;
    }
    fleet.clear();

    return 0;
}
