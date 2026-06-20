#ifndef ENGINE_ECU_HPP
#define ENGINE_ECU_HPP

#include "ECU.hpp"

class EngineECU : public ECU
{
private:
    int currentSpeed;
public:
    EngineECU(int id, const std::string& name, CanBus& bus, int currentSpeed);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    void process() override;

};


#endif // ENGINE_ECU_HPP