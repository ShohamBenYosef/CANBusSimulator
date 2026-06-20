#include "DashboardECU.hpp"

#include <iostream>

DashboardECU::DashboardECU(int id, const std::string& name, CanBus& bus)
        : ECU(id, name, bus), displayedSpeed(0), displayedFuel(0), displayedTemperature(0)
        {}

void DashboardECU::process(){
    while (bus.hasMessage()) {
        CanMessage message = bus.receive();
        handleMessage(message);
    }
}

void DashboardECU::handleMessage(const CanMessage& message) {
    switch (message.getType())
    {
    case MessageType::Speed:
        displayedSpeed = message.getPayload();
        break;
    
    case MessageType::Fuel:
        displayedFuel = message.getPayload();
        break;

    case MessageType::Temperature:
        displayedTemperature = message.getPayload();
        break;
    
    default:
        break;
    }
}

void DashboardECU::display() const {
    std::cout << "Speed: " << getDisplayedSpeed() << "\n"
            << "Fuel: " << getDisplayedFuel() << "\n"
            << "Temperature: " << getDisplayedTemperature() << "\n";
}



int DashboardECU::getDisplayedSpeed() const{
    return displayedSpeed;
}

int DashboardECU::getDisplayedTemperature() const {
    return displayedTemperature;
}

int DashboardECU::getDisplayedFuel() const{
    return displayedFuel;
}