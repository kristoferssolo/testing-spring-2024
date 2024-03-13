#ifndef ROOM_HH
#define ROOM_HH

#include "player.hh"

#include <cstdint>
#include <ctime>
#include <initializer_list>
#include <string>
#include <vector>

namespace room {
    enum Status {
        AwaitingStart,
        InProgress,
        Stopped,
        Ended,
    };
}

struct Room {
    uint32_t id;
    std::string title;
    std::tm *created_at;
    room::Status status;
    std::vector<Player> players;

    Room(uint32_t id, std::string title, uint32_t created_at, room::Status status, std::vector<Player> players);
    Room(
      uint32_t id, std::string title, uint32_t created_at, room::Status status, std::initializer_list<Player> players);
};

#endif  // !ROOM_HH
