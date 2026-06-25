#include "CanBus.hpp"
#include "EngineECU.hpp"
#include "DashboardECU.hpp"
#include "FaultType.hpp"

#include <cassert>

int main()
{
    CanBus bus(100);

    EngineECU engine(1, "Engine", bus);
    DashboardECU dashboard(2, "Dashboard", bus);

    engine.setSpeed(80);
    engine.setFuelLevel(-10);
    engine.setTemperature(90);

    engine.process();
    dashboard.process();

    assert(dashboard.hasWarning());

    const auto& faults = dashboard.getFaults();

    assert(faults.size() == 1);
    assert(faults[0] == FaultType::InvalidFuel);

    return 0;
}