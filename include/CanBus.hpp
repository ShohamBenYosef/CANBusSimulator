#ifndef CAN_BUS_HPP
#define CAN_BUS_HPP

#include <vector>
#include <optional>
#include <cstddef>
#include "CanMessage.hpp"
#include <mutex>

class CanBus
{
private:
    mutable std::mutex mutex;
    std::vector<std::optional<CanMessage>> buffer;
    size_t capacity;
    size_t writeCounter;

public:
    explicit CanBus(size_t capacity);

    void send(const CanMessage& message);
    
    CanMessage receive(size_t& readCounter);
    bool hasMessage(size_t readCounter) const;
    
    size_t getCurrentWriteCounter() const;

};




#endif // CAN_BUS_HPP