#include "CanMessage.hpp"

CanMessage::CanMessage(const std::string& sender, MessageType type,int payload, int priority)
        : sender(sender), type(type), payload(payload), priority(priority),
         timestamp(std::chrono::steady_clock::now()) 
         {
         }


const std::string CanMessage::getSender() const {
    return sender;
}

MessageType CanMessage::getType() const {
    return type;
}

int CanMessage::getPayload() const {
    return payload;
}

int CanMessage::getPriority() const {
    return priority;
}

std::chrono::steady_clock::time_point CanMessage::getTimestamp() const{
    return timestamp;
}