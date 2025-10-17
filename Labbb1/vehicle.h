#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string name_;
    short fuelLevel_; // [0,100]
    void normalizeFuelLevel();

public:
    Vehicle(const std::string& name, short fuelLevel = 100);
    virtual ~Vehicle();

    const std::string& getName() const;
    short getFuelLevel() const;

    virtual void refuel(short amount) = 0;
    virtual std::string status() const = 0;

    // default: burn 5 per hour (no prints)
    virtual void simulateHour();
};

#endif // VEHICLE_H
