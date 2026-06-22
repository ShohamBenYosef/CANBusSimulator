#include "CanBus.hpp"
#include "EngineECU.hpp"
#include "DashboardECU.hpp"
#include "LoggerECU.hpp"

#include <iostream>

int main()
{
    std::cout << "CAN Bus Simulator started\n";
    
    CanBus bus(100);

    EngineECU engine(1, "EngineECU", bus);
    DashboardECU dashboard(2,"DashboardECU", bus);
    LoggerECU logger(3, "LoggerECU", bus);

    engine.setSpeed(80);
    engine.setFuelLevel(65);
    engine.setTemperature(90);

    engine.process();

    std::cout << "--- Experiment 1: dashboard reads first ---\n";
    
    dashboard.process();
    logger.process();
    dashboard.display();

    std::cout << "\n--- Experiment 2: Logger reads first ---\n";
    
    engine.setSpeed(120);
    engine.setFuelLevel(50);
    engine.setTemperature(95);

    engine.process();

    logger.process();
    dashboard.process();
    dashboard.display();






    return 0;
}