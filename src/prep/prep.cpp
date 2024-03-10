#include "prep.hh"

#include "timeUtils.hh"

#include <initializer_list>

int add(int a, int b) {
    return a + b;
}

Action::Action(std::string name, bool hasTarget) {
    this->name = name;
    this->hasTarget = hasTarget;
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

Event::Event(std::string title,
             uint32_t utcTimestampCreatedAt,
             uint32_t numberNight,
             bool isVisible,
             std::vector<Action> causedBy,
             std::vector<Action> prohibits,
             std::vector<Action> allows):
    title(title),
    utcTimestampCreatedAt(createUTCTimestamp(utcTimestampCreatedAt)),
    numberNight(numberNight),
    isVisible(isVisible) {
    this->utcTimestampCreatedAt = createUTCTimestamp(utcTimestampCreatedAt);
    for (auto &a : causedBy) {
        this->causedBy.push_back(a);
    }
    for (auto &a : prohibits) {
        this->prohibits.push_back(a);
    }
    for (auto &a : allows) {
        this->allows.push_back(a);
    }
}

Event::Event(std::string title,
             uint32_t utcTimestampCreatedAt,
             uint32_t numberNight,
             bool isVisible,
             std::initializer_list<Action> causedBy,
             std::initializer_list<Action> prohibits,
             std::initializer_list<Action> allows):
    Event(title,
          utcTimestampCreatedAt,
          numberNight,
          isVisible,
          std::vector<Action>(causedBy),
          std::vector<Action>(prohibits),
          std::vector<Action>(allows)) {
    this->utcTimestampCreatedAt = createUTCTimestamp(utcTimestampCreatedAt);
}
