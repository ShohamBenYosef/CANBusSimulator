#include "CanBus.hpp"
#include "EngineECU.hpp"
#include "DashboardECU.hpp"




#include <iostream>

int main()
{
    std::cout << "CAN Bus Simulator started\n";
    
    CanBus bus;

    EngineECU engine(1, "engine1", bus);
    DashboardECU dashboard(2,"dashboard2", bus);

    engine.setSpeed(80);
    engine.setFuelLevel(65);
    engine.setTemperature(90);

    engine.process();

    dashboard.process();
    dashboard.display();

    std::cout << "\nUpdating engine state...\n\n";

    engine.setSpeed(120);
    engine.setFuelLevel(50);
    engine.setTemperature(95);

    engine.process();

    dashboard.process();
    dashboard.display();



    return 0;
}