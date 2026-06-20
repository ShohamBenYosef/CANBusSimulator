#ifndef CAN_BUS_HPP
#define CAN_BUS_HPP

#include <queue>
#include "CanMessage.hpp"


class CanBus
{
private:
    std::queue<CanMessage> messagesQueue;

public:
    void send(const CanMessage& message);
    CanMessage receive();
    bool hasMessage() const;
};




#endif // CAN_BUS_HPP