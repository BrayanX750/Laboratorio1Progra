#include "Car.h"
#include <string>

Car::Car(const std::string& name, short fuelLevel)
    : Vehicle(name, fuelLevel) {}

Car::~Car() {}

void Car::refuel(short amount) {
    fuelLevel_ = static_cast<short>(fuelLevel_ + amount);
    normalizeFuelLevel();
}

std::string Car::status() const {
    return "Car: " + name_ + " | Fuel Level=" + std::to_string(fuelLevel_);
}

void Car::simulateHour() {
    fuelLevel_ -= 6;
    normalizeFuelLevel();
}
