#include "room.hh"

#include <cstdint>
#include <initializer_list>
#include <string>
#include <vector>

Room::Room(uint32_t id, std::string title, uint32_t created_at, RoomStatus status, std::vector<Player> players):
    id(id),
    title(title),
    created_at(createUTCTimestamp(created_at)),
    status(status),
    players(players) {
}

Room::Room(
  uint32_t id, std::string title, uint32_t created_at, RoomStatus status, std::initializer_list<Player> players):
    id(id),
    title(title),
    created_at(createUTCTimestamp(created_at)),
    status(status),
    players(players) {
}
