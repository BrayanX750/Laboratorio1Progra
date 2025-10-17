#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(const std::string& name, short fuelLevel = 100);
    virtual ~Truck();

    void refuel(short amount = 15) override;
    std::string status() const override;
    void simulateHour() override;
};

#endif // TRUCK_H
