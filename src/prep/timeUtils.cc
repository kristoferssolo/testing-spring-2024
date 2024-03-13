#include "timeUtils.hh"

#include <chrono>
#include <cstdint>
#include <ctime>

std::tm *createUTCTimestamp(uint32_t timestamp) {
    // Convert the timestamp into a time_point object
    std::chrono::seconds sec(timestamp);
    std::chrono::time_point<std::chrono::system_clock> tp(sec);
    // Convert to time_t for formatting
    std::time_t time_object = std::chrono::system_clock::to_time_t(tp);
    // Convert to tm as UTC time
    return std::gmtime(&time_object);
}
