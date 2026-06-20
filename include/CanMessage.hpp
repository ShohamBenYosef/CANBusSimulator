#ifndef CAN_MESSAGE_HPP
#define CAN_MESSAGE_HPP

#include <string>
#include <chrono>


enum class MessageType{
    Speed,
    Temperature,
    Brake,
    Fuel
};

class CanMessage
{
private:
    std::string sender;
    MessageType type;
    int payload;
    int priority;
    std::chrono::steady_clock::time_point timestamp;

public:
    CanMessage(const std::string& sender, MessageType type, int payload, int priority);
    const std::string getSender() const;
    MessageType getType() const;
    int getPayload() const;
    int getPriority() const;
    std::chrono::steady_clock::time_point getTimestamp() const;
};





#endif // CAN_MESSAGE_HPP