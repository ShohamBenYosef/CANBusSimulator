#ifndef FAULT_TYPE_HPP
#define FAULT_TYPE_HPP

#include <string>

enum class FaultType {
    None,
    InvalidSpeed,
    InvalidFuel,
    InvalidTemperature,
    BufferOverflow
};


std::string faultTypeToString(FaultType fault);

#endif // FAULT_TYPE_HPP
