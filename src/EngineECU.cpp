#include "EngineECU.hpp"

EngineECU::EngineECU(int id, const std::string& name, CanBus& bus, int currentSpeed)
    : ECU(id,name, bus), currentSpeed(currentSpeed)
    {}


int EngineECU::getSpeed() const {
    return currentSpeed;
}

void EngineECU::setSpeed(int newSpeed) {
    currentSpeed = newSpeed;
}

void EngineECU::process() {
    CanMessage message(
        name, MessageType::Speed,
        currentSpeed, 
        1
    );
    
    bus.send(message);
}