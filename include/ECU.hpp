#ifndef ECU_HPP
#define ECU_HPP

#include "CanBus.hpp"
#include <string>

class ECU
{
protected:
    uint32_t id;
    std::string name;
    CanBus& bus;
    size_t readIndex;

public:
    ECU(uint32_t id, const std::string& name, CanBus& bus);
    virtual ~ECU() = default;
    virtual void process() = 0;

    uint32_t getId() const;
    const std::string& getName() const;

};




#endif // ECU_HPP