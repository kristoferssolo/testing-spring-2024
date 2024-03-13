#include "./player.hh"

#include "./role.hh"

#include <string>

Player::Player(uint32_t id, std::string username, Role role, player::Status status):
    id(id),
    username(username),
    role(role),
    status(status) {
}

bool Player::operator==(const Player &other) const {
    return this->id == other.id;
}
