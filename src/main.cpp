#include <iostream>
#include "Event.h"
#include "Order.h"
#include "Parser.h"

int main() {
    std::cout << "TradingSim starting...\n";

    Event event1(EventType::ADD, 1622548800000, 1, 10000, 10, Side::BUY);
    std::cout << event1 << std::endl;

    Order order1(1, Side::BUY, OrderType::LIMIT, 10000, 10, 1622548800000);
    std::cout << order1 << std::endl;


    std::vector<Event> events = parseFile("data/sample_feed.csv");

    std::cout << "Parsed " << events.size() << " events:\n\n";
    for (const auto& event : events) {
        std::cout << event << "\n";
    }

    return 0;
}