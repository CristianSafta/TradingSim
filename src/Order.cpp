#include "Order.h"

std::string toString(Side side) {
    switch (side) {
        case Side::BUY:  return "BUY";
        case Side::SELL: return "SELL";
        default:         return "UNKNOWN";
    }
}

std::string toString(OrderType type) {
    switch (type) {
        case OrderType::MARKET: return "MARKET";
        case OrderType::LIMIT:  return "LIMIT";
        default:                return "UNKNOWN";
    }
}

Order::Order(int orderId,
             Side side,
             OrderType type,
             int price,
             int quantity,
             long long timestamp)
    : orderId(orderId),
      side(side),
      type(type),
      price(price),
      quantity(quantity),
      timestamp(timestamp) {}


std::ostream& operator<<(std::ostream& os, const Order& order) {
            os << "Order{"
               << "id=" << order.orderId
               << ", side=" << toString(order.side)
               << ", type=" << toString(order.type)
               << ", price=" << order.price
               << ", qty=" << order.quantity
               << ", time=" << order.timestamp
               << "}";
            return os;
}