cmake_minimum_required(VERSION 3.16)
project(CANBusSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(CANBusSimulator
    src/main.cpp
    src/CanMessage.cpp
    src/CanBus.cpp
    src/ECU.cpp
    src/EngineECU.cpp
    src/DashboardECU.cpp
)