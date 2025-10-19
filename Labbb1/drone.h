#ifndef DRONE_H
#define DRONE_H

#include "Vehicle.h"
#include "IFlyable.h"

class Drone : public Vehicle, public IFlyable {
public:
    Drone(const std::string& name, short batteryLevel = 100);
    virtual ~Drone();

    void refuel(short amount = 15) override;
    std::string status() const override;
    void simulateHour() override;


    void fly(int minutes = 5) override;
};

#endif // DRONE_H
