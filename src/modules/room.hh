#pragma once

#include "./player.hh"

#include <cstdint>
#include <ctime>
#include <initializer_list>
#include <string>
#include <vector>

enum class RoomStatus {
    AwaitingStart,
    InProgress,
    Stopped,
    Ended,
};

struct Room {
    uint32_t id;
    std::string title;
    std::tm *created_at;
    RoomStatus status;
    std::vector<Player> players;

    Room(uint32_t id, std::string title, uint32_t created_at, RoomStatus status, std::vector<Player> players);
    Room(uint32_t id, std::string title, uint32_t created_at, RoomStatus status, std::initializer_list<Player> players);
};
