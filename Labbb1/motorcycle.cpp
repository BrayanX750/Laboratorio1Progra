#include "Motorcycle.h"
#include <iostream>
#include <string>

Motorcycle::Motorcycle(const std::string& name, short fuelLevel)
    : Vehicle(name, fuelLevel) {}

Motorcycle::~Motorcycle() {}

void Motorcycle::refuel(short amount) {

    short gained = static_cast<short>((amount * 4) / 5);
    fuelLevel_ = static_cast<short>(fuelLevel_ + gained);
    normalizeFuelLevel();
}

std::string Motorcycle::status() const {
    return "Motorcycle: " + name_ + " | Fuel Level=" + std::to_string(fuelLevel_);
}

void Motorcycle::simulateHour() {
    fuelLevel_ -= 4;
    normalizeFuelLevel();

    if (fuelLevel_ < 20) {
        std::cout << "[Warning] Motorcycle " << name_
                  << " is running low on fuel (" << fuelLevel_ << "%)" << std::endl;
    }
}
