#pragma once

#include <string>
#include <iostream>

enum class Side {
    BUY,
    SELL
};

std::string toString(Side side);



enum class OrderType {
    MARKET,
    LIMIT
};


std::string toString(OrderType type);

struct Order {
    public:
        int orderId;
        Side side;
        OrderType type;
        int price; // For limit orders, price in cents, for market orders, price is ignored or set to 0
        int quantity;
        long long timestamp;

        Order(int orderId,
          Side side,
          OrderType type,
          int price,
          int quantity,
          long long timestamp);

        
        
};

std::ostream& operator<<(std::ostream& os, const Order& order);