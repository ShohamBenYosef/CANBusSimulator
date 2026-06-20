#include "CanBus.hpp"
#include <stdexcept>

void CanBus::send(const CanMessage& message) {
    messagesQueue.push(message);
}

CanMessage CanBus::receive() {
    if (this->messagesQueue.empty()) {
        throw std::runtime_error("Queue is empty");
    }
    
    CanMessage message = messagesQueue.front();
    messagesQueue.pop();

    return message;
    
}

bool CanBus::hasMessage() const {
    return !messagesQueue.empty();
}