#include "CanBus.hpp"
#include "EngineECU.hpp"
#include "DashboardECU.hpp"
#include "LoggerECU.hpp"

#include <iostream>

int main() {
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

    try {
        logger.process();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    dashboard.display();


    return 0;
}