#pragma once

#include "./action.hh"

#include <cstdint>
#include <ctime>
#include <initializer_list>
#include <string>
#include <vector>

enum class EventType {
    PhaseChange,
    EventAction,
    RoomStateChange,
    PlayerStateChange,
};

struct Event {
    std::string title;
    std::tm *created_at;
    uint32_t night_number;
    bool is_visible;
    std::vector<Action> prohibits;
    std::vector<Action> allows;
    bool operator<(const Event &other) const;
    bool operator==(const Event &other) const;
    bool operator>(const Event &other) const;

    Event(std::string title,
          uint32_t created_at,
          uint32_t night_number,
          bool is_visible,
          std::vector<Action> prohibits,
          std::vector<Action> allows);
    Event(std::string title,
          uint32_t created_at,
          uint32_t night_number,
          bool is_visible,
          std::initializer_list<Action> prohibits,
          std::initializer_list<Action> allows);
};
