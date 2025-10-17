#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(const std::string& name, short fuelLevel = 100);
    virtual ~Car();

    void refuel(short amount = 15) override;
    std::string status() const override;
    void simulateHour() override;
};

#endif // CAR_H
