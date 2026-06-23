#ifndef DASHBOARD_ECU_HPP
#define DASHBOARD_ECU_HPP

#include "ECU.hpp"
#include "FaultType.hpp"
#include <vector>

class DashboardECU : public ECU
{
private:
    int displayedSpeed;
    int displayedTemperature;
    int displayedFuel;
    std::vector<FaultType> faults;
    size_t readCounter;
    
    void handleMessage(const CanMessage& message);
    
public:
    DashboardECU(int id, const std::string& name, CanBus& bus);
    
    void process() override;
    
    void display() const;
    bool hasWarning() const;

    const std::vector<FaultType>& getFaults() const;
    int getDisplayedSpeed() const;
    int getDisplayedTemperature() const;
    int getDisplayedFuel() const;
};


#endif // DASHBOARD_ECU_HPP