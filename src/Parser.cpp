#include "Parser.h"
#include <sstream>
#include <iostream>
#include <fstream>

// Helper function to convert string to EventType enum
EventType parseEventType(const std::string& str){
    if(str == "ADD") return EventType::ADD;
    if(str == "CANCEL") return EventType::CANCEL;
    if(str == "MODIFY") return EventType::MODIFY;
    if(str == "TRADE") return EventType::TRADE;
    throw std::invalid_argument("Unknown event type: " + str);
}

// Helper function to convert string to Side enum
Side parseSide(const std::string& str){
    if(str == "BUY") return Side::BUY;
    if(str == "SELL") return Side::SELL;
    throw std::invalid_argument("Unknown side: " + str);
}

std::optional<Event> parseLine(const std::string& line){

    std::vector<std::string> tokens;
    std::stringstream lineSs(line);

    std::string token;
    while (std::getline(lineSs, token, ',')){
        tokens.push_back(token);
    }

    if(tokens.size() != 6){
        std::cerr << "Warning: Malformed line (expected 6 fields, got " << tokens.size() << "): " << line << std::endl;
        return std::nullopt;
    }

    
    try {
        long long timestamp = std::stoll(tokens[0]);
        EventType eventType = parseEventType(tokens[1]);
        int orderId = std::stoi(tokens[2]);
        Side side = parseSide(tokens[3]);
        int price = std::stoi(tokens[4]);
        int quantity = std::stoi(tokens[5]);
        return Event(eventType, timestamp, orderId, price, quantity, side);
        
    } catch (const std::exception& e) {
        std::cerr << "Warning: Malformed line (error parsing fields): " << line << " - " << e.what() << std::endl;
        return std::nullopt;
    }
}



std::vector<Event> parseFile(const std::string& filename){
    std::vector<Event> events;
    std::ifstream inFile;
    inFile.open(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return events;
    }

    std::string line;
    // Skip header
    std::getline(inFile, line);

    while(std::getline(inFile, line)){
        auto eventOpt = parseLine(line);
        if(eventOpt){
            events.push_back(*eventOpt);
        }
    }


    return events;
}