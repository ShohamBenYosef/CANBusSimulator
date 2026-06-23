# CAN Bus Simulator Architecture

## Overview

This project simulates a small CAN Bus-based communication system between Electronic Control Units (ECUs).

The goal is to practice C++ system design concepts that are common in embedded software, automotive systems, validation, and verification environments.

## Main Components

### CanMessage

Represents a single message sent over the bus.

Each message contains:

* Sender name
* Message type
* Payload value
* Priority
* Timestamp

Supported message types:

* Speed
* Fuel
* Temperature
* Brake

### CanBus

Represents the shared communication channel between ECUs.

The bus is implemented as a fixed-size ring buffer.

It stores messages in a circular buffer and uses a global `writeCounter` to track how many messages were written.

Each consumer ECU keeps its own `readCounter`.

This allows multiple consumers to read the same messages independently.

```text
EngineECU
    |
    v
 CanBus Ring Buffer
    |
    +--> DashboardECU
    |
    +--> LoggerECU
```

### Ring Buffer Behavior

The bus has a fixed capacity.

When a new message is sent:

```text
index = writeCounter % capacity
```

The message is written into that slot, and `writeCounter` is incremented.

This means old messages can be overwritten when the buffer wraps around.

### Missed Message Detection

If a consumer is too slow, it may miss messages.

This is detected by comparing:

```text
writeCounter - readCounter > capacity
```

If this condition is true, the consumer missed messages that were already overwritten.

In this case, the bus throws an exception instead of silently returning invalid data.

### ECU

Abstract base class for all electronic control units.

Common ECU data:

* ID
* Name
* Reference to the shared CanBus

Each derived ECU must implement:

```cpp
process()
```

### EngineECU

Represents an engine control unit.

Internal state:

* Current speed
* Fuel level
* Engine temperature

When `process()` is called, the EngineECU sends its current state as CAN messages.

### DashboardECU

Represents the dashboard display unit.

Internal state:

* Displayed speed
* Displayed fuel level
* Displayed temperature
* Read counter

When `process()` is called, the DashboardECU reads all available messages from the bus using its own `readCounter`.

It updates its displayed values according to the received message types.

### LoggerECU

Represents a logging ECU.

Internal state:

* Read counter

When `process()` is called, the LoggerECU reads all available messages from the bus using its own `readCounter` and prints them.

Because the LoggerECU has its own read counter, it can read the same messages as the DashboardECU.

## Current Data Flow

```text
EngineECU
   |
   | sends Speed / Fuel / Temperature messages
   v
CanBus Ring Buffer
   |
   +--> DashboardECU updates displayed values
   |
   +--> LoggerECU logs messages
```

## Design Patterns Used

### Producer / Multiple Consumers

`EngineECU` acts as the producer.

`DashboardECU` and `LoggerECU` act as independent consumers.

### Ring Buffer

The bus uses fixed-size memory and cyclic indexing.

This is useful for embedded-style systems where memory usage should be bounded.

### State and Behavior Separation

Each ECU owns its internal state.

Calling `process()` causes the ECU to act based on that state.

## Current Limitations

* No multithreading yet
* No mutex or condition variable protection
* No real CAN frame format
* No message ID arbitration
* No hardware-level filtering
* No unit test framework yet

## Planned Improvements

* Unit tests
* Fault injection
* Message validation
* Multithreaded ECU simulation
* Mutex-protected CanBus
* Condition variable for blocking reads
* More ECU types
* Better logging format
* Verification-style test scenarios
