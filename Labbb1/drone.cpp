#include "Drone.h"
#include <iostream>
#include <string>

Drone::Drone(const std::string& name, short batteryLevel)
    : Vehicle(name, batteryLevel) {}

Drone::~Drone() {}

void Drone::refuel(short amount) {

    short gained = static_cast<short>((amount * 3) / 2);
    fuelLevel_ = static_cast<short>(fuelLevel_ + gained);
    normalizeFuelLevel();
}

std::string Drone::status() const {
    return "Drone: " + name_ + " | Battery=" + std::to_string(fuelLevel_);
}

void Drone::simulateHour() {
    fuelLevel_ -= 8;
    normalizeFuelLevel();
}

void Drone::fly(int minutes) {

    short burn = static_cast<short>(minutes * 3);
    fuelLevel_ = static_cast<short>(fuelLevel_ - burn);
    normalizeFuelLevel();
    std::cout << name_ << " flew for " << minutes << " minutes." << std::endl;
}
