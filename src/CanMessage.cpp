#include "CanMessage.hpp"

CanMessage::CanMessage(const std::string& sender, MessageType type,int payload, int priority)
        : sender(sender), type(type), payload(payload), priority(priority),
         timestamp(std::chrono::steady_clock::now()) 
         {
         }


const std::string CanMessage::getSender() const {
    return this->sender;
}

MessageType CanMessage::getType() const {
    return this->type;
}

int CanMessage::getPayload() const {
    return this->payload;
}

int CanMessage::getPriority() const {
    return this->priority;
}

std::chrono::steady_clock::time_point CanMessage::getTimestamp() const{
    return this->timestamp;
}