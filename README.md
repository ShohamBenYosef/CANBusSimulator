# CAN Bus Simulator

A C++ project that simulates communication between Electronic Control Units (ECUs) over a CAN Bus network.

The goal of this project is to learn and practice:

* Modern C++
* Object-Oriented Programming
* System Design
* Embedded Software Concepts
* Message-Based Communication
* Verification and Testing Concepts

## Current Features

* CAN message representation
* CAN bus message queue
* Abstract ECU base class
* Engine ECU implementation
* CMake build system

## Planned Features

* Dashboard ECU
* Multiple ECU communication
* Message filtering
* Multithreading
* Fault injection
* Verification framework
* Unit tests

## Project Structure

```text
include/
src/
tests/
docs/
```

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/CANBusSimulator
```

This project is intended as a learning-oriented simulation of concepts commonly found in automotive and embedded systems.
