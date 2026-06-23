#include "FaultType.hpp"


std::string faultTypeToString(FaultType fault) {
    switch (fault)
    {
    case FaultType::InvalidSpeed:
        return "InvalidSpeed";
    
    case FaultType::InvalidFuel:
        return "InvalidFuel";
    
    case FaultType::InvalidTemperature:
        return "InvalidTemperature";

    case FaultType::BufferOverflow:
        return "BufferOverflow";
    
    default:
        break;
    }
    
    return "Unknown";
}