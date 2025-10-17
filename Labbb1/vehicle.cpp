#include "Vehicle.h"

Vehicle::Vehicle(const std::string& name, short fuelLevel)
    : name_(name), fuelLevel_(fuelLevel) {
    normalizeFuelLevel();
}

Vehicle::~Vehicle() {}

void Vehicle::normalizeFuelLevel() {
    if (fuelLevel_ < 0) fuelLevel_ = 0;
    else if (fuelLevel_ > 100) fuelLevel_ = 100;
}

const std::string& Vehicle::getName() const { return name_; }
short Vehicle::getFuelLevel() const { return fuelLevel_; }

void Vehicle::simulateHour() {
    fuelLevel_ -= 5;
    normalizeFuelLevel();
}
