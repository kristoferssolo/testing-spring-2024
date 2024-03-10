#include "prep.hh"

#include "timeUtils.hh"

#include <initializer_list>

int add(int a, int b) {
    return a + b;
}

Role::Role(std::initializer_list<Action> actions) {
    for (auto &a : actions) {
        this->actions.push_back(a);
    }
}

Role::Role(std::vector<Action> actions) {
    for (auto &a : actions) {
        this->actions.push_back(a);
    }
}

Player::Player(std::string username, Role role, PlayerStatus playerStatus):
    username(username),
    role(role),
    playerStatus(playerStatus) {
}

Room::Room(uint32_t id, std::string title, uint32_t utcTimestampCreatedAt, RoomStatus status):
    id(id),
    title(title),
    status(status) {
    this->utcTimestampCreatedAt = createUTCTimestamp(utcTimestampCreatedAt);
}

Event::Event(std::string title, uint32_t utcTimestampCreatedAt, uint32_t numberNight, bool isVisible):
    title(title),
    utcTimestampCreatedAt(createUTCTimestamp(utcTimestampCreatedAt)),
    numberNight(numberNight),
    isVisible(isVisible) {
    this->utcTimestampCreatedAt = createUTCTimestamp(utcTimestampCreatedAt);
}
