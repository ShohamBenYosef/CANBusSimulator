#include "EngineECU.hpp"

EngineECU::EngineECU(uint32_t id, const std::string& name, CanBus& bus)
    : ECU(id,name, bus), currentSpeed(0),currentFuel(0),currentTemperature(0)
    {}


int EngineECU::getSpeed() const {
    return currentSpeed;
}

int EngineECU::getFuel() const {
    return currentFuel;
}

int EngineECU::getTemperature() const {
    return currentTemperature;
}

void EngineECU::setSpeed(int newSpeed) {
    currentSpeed = newSpeed;
}

void EngineECU::setFuelLevel(int newFuel) {
    currentFuel = newFuel;
}

void EngineECU::setTemperature(int newTemperature) {
    currentTemperature = newTemperature;
}


void EngineECU::process() {
    bus.send(CanMessage(name, MessageType::Speed, currentSpeed, 1));
    bus.send(CanMessage(name, MessageType::Fuel, currentFuel, 1));
    bus.send(CanMessage(name, MessageType::Temperature, currentTemperature, 1));
}