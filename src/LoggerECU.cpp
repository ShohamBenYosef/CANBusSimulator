#include "LoggerECU.hpp"
#include <iostream>

LoggerECU::LoggerECU(uint32_t id, const std::string& name, CanBus& bus) 
    : ECU(id, name, bus), readCounter(0)
    {}

static std::string messageTypeToString(MessageType type) {
    switch (type)
    {
    case MessageType::Speed:
        return "Speed";
        break;
    case MessageType::Fuel:
        return "Fuel";
        break;
    case MessageType::Temperature:
        return "Temperature";
        break;
    
    default:
        return "Unknown";
        break;
    }
}

void LoggerECU::process() {
    while(bus.hasMessage(readCounter)) {
        CanMessage message = bus.receive(readCounter);
        std::cout << "[LOG] "
                << message.getSender() << "|"
                << messageTypeToString(message.getType()) << "|"
                << message.getPayload() << "|"
                << message.getPriority() << "|" 
                << "\n";
    }
}

