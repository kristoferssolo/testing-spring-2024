#include "prep.hh"

#include "timeUtils.hh"

#include <cstdint>
#include <initializer_list>

int add(int a, int b) {
    return a + b;
}

Action::Action(std::string name, bool hasTarget) {
    this->name = name;
    this->hasTarget = hasTarget;
}

bool Action::operator==(const Action &other) const {
    return this->name == other.name;
}

Role::Role(std::initializer_list<Action> actions): Role(std::vector<Action>(actions)) {
}

Role::Role(std::vector<Action> actions): actions(actions) {
}

Player::Player(uint32_t id, std::string username, Role role, PlayerStatus playerStatus):
    id(id),
    username(username),
    role(role),
    playerStatus(playerStatus) {
}

bool Player::operator==(const Player &other) const {
    return this->id == other.id;
}

Room::Room(
  uint32_t id, std::string title, uint32_t utcTimestampCreatedAt, RoomStatus status, std::vector<Player> players):
    id(id),
    title(title),
    status(status),
    players(players) {
    this->utcTimestampCreatedAt = createUTCTimestamp(utcTimestampCreatedAt);
}

Room::Room(uint32_t id,
           std::string title,
           uint32_t utcTimestampCreatedAt,
           RoomStatus status,
           std::initializer_list<Player> players):
    Room(id, title, utcTimestampCreatedAt, status, std::vector<Player>(players)) {
    this->utcTimestampCreatedAt = createUTCTimestamp(utcTimestampCreatedAt);
}

Event::Event(std::string title,
             uint32_t utcTimestampCreatedAt,
             uint32_t numberNight,
             bool isVisible,
             std::vector<Action> prohibits,
             std::vector<Action> allows):
    title(title),
    utcTimestampCreatedAt(createUTCTimestamp(utcTimestampCreatedAt)),
    numberNight(numberNight),
    isVisible(isVisible),
    prohibits(prohibits),
    allows(allows) {
    this->utcTimestampCreatedAt = createUTCTimestamp(utcTimestampCreatedAt);
}

Event::Event(std::string title,
             uint32_t utcTimestampCreatedAt,
             uint32_t numberNight,
             bool isVisible,
             std::initializer_list<Action> prohibits,
             std::initializer_list<Action> allows):
    Event(title,
          utcTimestampCreatedAt,
          numberNight,
          isVisible,
          std::vector<Action>(prohibits),
          std::vector<Action>(allows)) {
    this->utcTimestampCreatedAt = createUTCTimestamp(utcTimestampCreatedAt);
}

bool Event::operator<(const Event &right) const {
    return this->utcTimestampCreatedAt < right.utcTimestampCreatedAt;
}

bool Event::operator==(const Event &right) const {
    return this->utcTimestampCreatedAt == right.utcTimestampCreatedAt;
}

bool Event::operator>(const Event &right) const {
    return this->utcTimestampCreatedAt > right.utcTimestampCreatedAt;
}
