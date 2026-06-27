#include "CanBus.hpp"
#include <stdexcept>

CanBus::CanBus(size_t cap)
    : capacity(cap), writeCounter(0)
    {
        buffer.resize(capacity);
    }


void CanBus::send(const CanMessage& message) {
    std::lock_guard<std::mutex> lock(mutex);
    size_t index = writeCounter % capacity;
    buffer[index] = message;
    ++writeCounter;
}

bool CanBus::hasMessage(size_t readCounter) const {
    std::lock_guard<std::mutex> lock(mutex);
    return readCounter < writeCounter;
}

CanMessage CanBus::receive(size_t& readCounter)
{
    std::lock_guard<std::mutex> lock(mutex);
    if (readCounter >= writeCounter) {
        throw std::runtime_error("No messages in the buffer for this reader.");
    }

    if (writeCounter - readCounter > capacity) {
        throw std::runtime_error("Missed messages.");
    }

    size_t index = readCounter % capacity;

    if (!buffer[index].has_value()) {
        throw std::runtime_error("Ring buffer slot empty.");
    }

    CanMessage message = buffer[index].value();
    ++readCounter;

    return message;
}

size_t CanBus::getCurrentWriteCounter() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return writeCounter;
}