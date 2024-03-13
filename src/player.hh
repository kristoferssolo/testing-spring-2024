#ifndef PLAYER_HH
#define PLAYER_HH

#include "role.hh"

#include <cstdint>
#include <string>

namespace player {
    enum Status {
        Kicked,
        Alive,
        Dead,
        VotedOut,
    };
}

struct Player {
    uint32_t id;
    std::string username;
    Role role;
    player::Status status;

    Player(uint32_t id, std::string username, Role role, player::Status status);
    bool operator==(const Player &other) const;
};

#endif  // !PLAYER_HH
