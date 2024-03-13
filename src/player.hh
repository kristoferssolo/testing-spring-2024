#ifndef PLAYER_HH
#define PLAYER_HH

#include "role.hh"

#include <cstdint>
#include <string>

enum PlayerStatus {
    Kicked,
    Alive,
    Dead,
    VotedOut,
};

struct Player {
    uint32_t id;
    std::string username;
    Role role;
    PlayerStatus status;

    Player(uint32_t id, std::string username, Role role, PlayerStatus status);
    bool operator==(const Player &other) const;
};

#endif  // !PLAYER_HH
