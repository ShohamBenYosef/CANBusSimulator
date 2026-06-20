#include "CanBus.hpp"
#include "EngineECU.hpp"
#include "DashboardECU.hpp"




#include <iostream>

int main()
{
    std::cout << "CAN Bus Simulator started\n";
    
    CanBus bus;
    EngineECU engine(1, "engine1", bus, 80);
    DashboardECU dashboard(2,"dashboard2", bus);

    engine.process();
    dashboard.process();
    dashboard.displaySpeed();

    return 0;
}