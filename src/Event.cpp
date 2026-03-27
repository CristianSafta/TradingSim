#include "Event.h"


std::string toString(EventType type) {
    switch (type) {
        case EventType::ADD:    return "ADD";
        case EventType::CANCEL: return "CANCEL";
        case EventType::MODIFY: return "MODIFY";
        case EventType::EXECUTE: return "EXECUTE";
        default:                return "UNKNOWN";
    }
}


Event::Event(EventType type,
             long long timestamp,
             int orderId,
             int price,
             int quantity,
             Side side)
    : type(type),
      timestamp(timestamp),
      orderId(orderId),
      price(price),
      quantity(quantity),
      side(side) {}

std::ostream& operator<<(std::ostream& os, const Event& event) {
    os << "Event{"
       << "type=" << toString(event.type)
       << ", time=" << event.timestamp
       << ", orderId=" << event.orderId
       << ", price=" << event.price
       << ", qty=" << event.quantity
       << ", side=" << toString(event.side)
       << "}";
    return os;
}