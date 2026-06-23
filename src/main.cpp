#include "CanBus.hpp"
#include "EngineECU.hpp"
#include "DashboardECU.hpp"
#include "LoggerECU.hpp"
#include "FaultType.hpp"

#include <iostream>

int main() {
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
    
    std::cout << "\n--- Experiment 3: Fault Injection ---\n";
    
    engine.setTemperature(500);
    engine.setFuelLevel(-10);

    engine.process();
    dashboard.process();

    if (dashboard.hasWarning())
    {
        std::cout << "Detected faults:\n";
        for (const auto& fault : dashboard.getFaults())
        {
            std::cout << faultTypeToString(fault) << "\n";
        }
    }
    /*
    std::cout << "CAN Bus Simulator started\n";
    
    CanBus bus(5);
    
    EngineECU engine(1, "EngineECU", bus);
    DashboardECU dashboard(2,"DashboardECU", bus);
    LoggerECU logger(3, "LoggerECU", bus);
    
    for (int i = 0; i < 10; ++i)
    {
        engine.setSpeed(i * 10);
        engine.setFuelLevel(100 - i);
        engine.setTemperature(80 + i);
        
        engine.process();
    }
    
    try
    {
        logger.process();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    dashboard.display();
    
    */

    return 0;
}