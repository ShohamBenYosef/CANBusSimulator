cmake_minimum_required(VERSION 3.16)
project(CANBusSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(COMMON_SOURCES
    src/CanMessage.cpp
    src/CanBus.cpp
    src/ECU.cpp
    src/EngineECU.cpp
    src/DashboardECU.cpp
    src/LoggerECU.cpp
    src/FaultType.cpp
)

add_executable(CANBusSimulator
    src/main.cpp
    ${COMMON_SOURCES}
)

enable_testing()

add_executable(test_dashboard
    tests/test_dashboard.cpp
    ${COMMON_SOURCES}
)

add_test(NAME DashboardTests COMMAND test_dashboard)