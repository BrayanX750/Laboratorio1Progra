#include "Truck.h"
#include <string>

Truck::Truck(const std::string& name, short fuelLevel)
    : Vehicle(name, fuelLevel) {}

Truck::~Truck() {}

void Truck::refuel(short amount) {
    short gained = static_cast<short>(amount / 2);
    fuelLevel_ = static_cast<short>(fuelLevel_ + gained);
    normalizeFuelLevel();
}

std::string Truck::status() const {
    return "Truck: " + name_ + " | Fuel Level=" + std::to_string(fuelLevel_);
}

void Truck::simulateHour() {
    fuelLevel_ -= 9;
    normalizeFuelLevel();
}
