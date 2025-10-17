#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle(const std::string& name, short fuelLevel = 100);
    virtual ~Motorcycle();

    void refuel(short amount = 15) override;
    std::string status() const override;
    void simulateHour() override;
};

#endif // MOTORCYCLE_H
