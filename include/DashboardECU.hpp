#ifndef DASHBOARD_ECU_HPP
#define DASHBOARD_ECU_HPP

#include "ECU.hpp"

class DashboardECU : public ECU
{
private:
    int displayedSpeed;
public:
    DashboardECU(int id, const std::string& name, CanBus& bus);
    void process() override;
    void displaySpeed() const;
    int getDisplayedSpeed() const;
};


#endif // DASHBOARD_ECU_HPP