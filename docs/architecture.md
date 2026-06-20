# CAN Bus Simulator Architecture

## Overview

This project simulates a small CAN Bus-based communication system between Electronic Control Units (ECUs).

The goal is to practice C++ system design concepts that are common in embedded software, automotive systems, and verification environments.

## Main Components

### CanMessage

Represents a single message sent over the bus.

Each message contains:

* Sender name
* Message type
* Payload value
* Priority
* Timestamp

Example message:

```text
Sender: EngineECU
Type: Speed
Payload: 120
```

### CanBus

Represents the communication channel between ECUs.

The bus stores messages in a queue.

ECUs can:

* Send messages into the bus
* Receive messages from the bus
* Check whether messages are waiting

Current behavior:

```text
First message in -> first message out
```

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

When `process()` is called, the DashboardECU reads all waiting messages from the bus and updates its displayed values.

## Current Data Flow

```text
EngineECU
   |
   | sends Speed / Fuel / Temperature messages
   v
CanBus
   |
   | delivers messages
   v
DashboardECU
```

## Current Design Pattern

The project currently follows a Producer / Queue / Consumer pattern:

```text
EngineECU     -> Producer
CanBus        -> Queue
DashboardECU  -> Consumer
```

## Future Improvements

Planned future features:

* More ECU types
* Message filtering
* Multiple consumers
* Fault injection
* Multithreading
* Verification tests
* Timing checks
