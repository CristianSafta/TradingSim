#pragma once

#include <string>
#include <iostream>
#include "Order.h"

enum class EventType {
    ADD,
    CANCEL,
    MODIFY,
    EXECUTE
};

std::string toString(EventType type);



class Event {
    public:
        EventType type;
        long long timestamp;
        int orderId; // ID of the order associated with this event
        int price;
        int quantity;
        Side side;

        Event(EventType type,
            long long timestamp,
            int orderId,
            int price,
            int quantity,
            Side side);

        
        
};

std::ostream& operator<<(std::ostream& os, const Event& event);