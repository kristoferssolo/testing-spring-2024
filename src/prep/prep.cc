#include "prep.hh"

#include "timeUtils.hh"

#include <cstdint>
#include <initializer_list>

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
