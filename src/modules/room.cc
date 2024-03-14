#include "./room.hh"

#include "./time.hh"

#include <cstdint>
#include <initializer_list>
#include <string>
#include <vector>

Room::Room(uint32_t id, std::string title, uint32_t created_at, RoomStatus status, std::vector<Player> players):
    id(id),
    title(title),
    status(status),
    players(players) {
    this->created_at = create_utc_timestamp(created_at);
}

Room::Room(
  uint32_t id, std::string title, uint32_t created_at, RoomStatus status, std::initializer_list<Player> players):
    id(id),
    title(title),
    status(status),
    players(players) {
    this->created_at = create_utc_timestamp(created_at);
}
