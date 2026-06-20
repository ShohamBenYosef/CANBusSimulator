#ifndef ENGINE_ECU_HPP
#define ENGINE_ECU_HPP

#include "ECU.hpp"

class EngineECU : public ECU
{
private:
    int currentSpeed;
    int currentFuel;
    int currentTemperature;

public:
    EngineECU(uint32_t id, const std::string& name, CanBus& bus);
    
    int getSpeed() const;
    int getFuel() const;
    int getTemperature() const;

    void setSpeed(int newSpeed);
    void setFuelLevel(int newFuel);
    void setTemperature(int newTemperature);
    
    void process() override;
};


#endif // ENGINE_ECU_HPP