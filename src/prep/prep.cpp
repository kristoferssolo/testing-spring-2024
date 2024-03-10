#include "prep.hh"

#include "timeUtils.hh"

int add(int a, int b) {
    return a + b;
}

Room::Room(uint32_t id, std::string title, uint32_t utcTimestampCreatedAt, RoomStatus status):
    id(id),
    title(title),
    status(status) {
    this->utcTimestampCreatedAt = createUTCTimestamp(utcTimestampCreatedAt);
}
