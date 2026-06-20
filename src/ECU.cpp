#include "ECU.hpp"

#include <cstdint>

ECU::ECU(uint32_t id, const std::string& name, CanBus& bus) 
        : id(id), name(name), bus(bus) {}

uint32_t ECU::getId() const {
    return id;
}

const std::string& ECU::getName() const {
    return name;
}