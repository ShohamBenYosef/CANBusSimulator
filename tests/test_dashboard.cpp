#include "CanBus.hpp"
#include "EngineECU.hpp"
#include "DashboardECU.hpp"
#include "FaultType.hpp"

#include <cassert>


void testInvalidFuel() {
    CanBus bus(100);

    EngineECU engine(1, "Engine", bus);
    DashboardECU dashboard(2, "Dashboard", bus);

    engine.setFuelLevel(-10);

    engine.process();
    dashboard.process();

    assert(dashboard.hasWarning());

    const auto& faults = dashboard.getFaults();

    assert(faults.size() == 1);
    assert(faults[0] == FaultType::InvalidFuel);
}

void testInvalidSpeed() {
    CanBus bus(100);

    EngineECU engine(1, "Engine", bus);
    DashboardECU dashboard(2, "Dashboard", bus);

    engine.setSpeed(-50);

    engine.process();
    dashboard.process();

    assert(dashboard.hasWarning());

    const auto& faults = dashboard.getFaults();

    assert(faults.size() == 1);
    assert(faults[0] == FaultType::InvalidSpeed);
}

void testInvalidTemperature() {
    CanBus bus(100);

    EngineECU engine(1, "Engine", bus);
    DashboardECU dashboard(2, "Dashboard", bus);

    engine.setTemperature(500);

    engine.process();
    dashboard.process();

    assert(dashboard.hasWarning());

    const auto& faults = dashboard.getFaults();

    assert(faults.size() == 1);
    assert(faults[0] == FaultType::InvalidTemperature);
}

void testValidValues() {
    CanBus bus(100);

    EngineECU engine(1, "Engine", bus);
    DashboardECU dashboard(2, "Dashboard", bus);

    engine.setSpeed(80);
    engine.setFuelLevel(50);
    engine.setTemperature(90);
    
    engine.process();
    dashboard.process();

    assert(!dashboard.hasWarning());
    assert(dashboard.getFaults().empty());
}

void testBufferOverflow() {
    CanBus bus(5);

    bool exceptionThrown = false;

    EngineECU engine(1, "Engine", bus);
    DashboardECU dashboard(2, "Dashboard", bus);

    for (int i = 0; i < 10; i++)
    {
        engine.process();
    }
    try
    {
        dashboard.process();
    }
    catch(const std::exception& e)
    {
        exceptionThrown = true;
    }
    
    assert(exceptionThrown);
}



int main() {
    testValidValues();
    testInvalidFuel();
    testInvalidSpeed();
    testInvalidTemperature();
    testBufferOverflow();

    return 0;
}