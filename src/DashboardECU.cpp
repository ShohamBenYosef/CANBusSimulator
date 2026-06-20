#include "DashboardECU.hpp"

#include <iostream>

DashboardECU::DashboardECU(int id, const std::string& name, CanBus& bus)
        : ECU(id, name, bus), displayedSpeed(0)
        {}

void DashboardECU::process() {
    CanMessage message = bus.receive();
    if (message.getType() == MessageType::Speed){
        displayedSpeed = message.getPayload();
    }

}

void DashboardECU::displaySpeed() const {
    std::cout << "Speed: " << getDisplayedSpeed() << "\n";
}


int DashboardECU::getDisplayedSpeed() const{
    return displayedSpeed;
}
