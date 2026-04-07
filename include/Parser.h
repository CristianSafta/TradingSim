#pragma once
#include <string>
#include <vector>
#include <optional>
#include "Event.h"


// Parse a single CSV line into an Event.
// Returns std::nullopt if the line is malformed.
std::optional<Event> parseLine(const std::string& line);

// Parse an entire CSV file into a vector of Events.
// Skips the header row. Logs warnings for malformed lines.
std::vector<Event> parseFile(const std::string& filename);
