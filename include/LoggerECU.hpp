#ifndef LOGGER_ECU_HPP
#define LOGGER_ECU_HPP

#include "ECU.hpp"

#include <cstdint>
#include <string>


class LoggerECU : public ECU
{
private:
    size_t readCounter;
    
public:
    LoggerECU(uint32_t id, const std::string& name, CanBus& bus);

    void process() override;
};



#endif // LOGGER_ECU_HPP