#include "DashboardECU.hpp"

#include <iostream>

DashboardECU::DashboardECU(int id, const std::string& name, CanBus& bus)
        : ECU(id, name, bus), displayedSpeed(0), displayedFuel(0), displayedTemperature(0), readCounter(0)
        {}

void DashboardECU::process(){
    while (bus.hasMessage(readCounter)) {
        CanMessage message = bus.receive(readCounter);
        handleMessage(message);
    }
}

void DashboardECU::handleMessage(const CanMessage& message) {

    int value = message.getPayload();
    
    switch (message.getType())
    {
    case MessageType::Speed:
        if (value < 0 || value > 200) {
            faults.push_back(FaultType::InvalidSpeed);
            break;
        }

        displayedSpeed = value;
        break;
    
    case MessageType::Fuel:
        if (value < 0 || value > 100) {
            faults.push_back(FaultType::InvalidFuel);
            break;
        }

        displayedFuel = value;
        break;

    case MessageType::Temperature:
        if (value < 0 || value > 150) {
            faults.push_back(FaultType::InvalidTemperature);
            break;
        }

        displayedTemperature = value;
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

bool DashboardECU::hasWarning() const {
    return !faults.empty();
}

const std::vector<FaultType>& DashboardECU::getFaults() const
{
    return faults;
}
