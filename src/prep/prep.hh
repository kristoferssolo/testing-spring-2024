#ifndef PREP_H
#define PREP_H

#include <cstdint>
#include <ctime>
#include <string>
#include <vector>

// All IDs are uint32_t
enum EventType {
    PHASE_CHANGE,
    ACTION,
    ROOM_STATE_CHANGE,
    PLAYER_STATE_CHANGE,
};

enum RoomStatus {
    AWAITING_START,
    IN_PROGRESS,
    STOPPED,
    ENDED,
};

struct Room;
struct Event;

struct Room {
    uint32_t id;
    std::string title;
    std::tm *utcTimestampCreatedAt;
    RoomStatus status;
    std::vector<Player> players;

    Room(
      uint32_t id, std::string title, uint32_t utcTimestampCreatedAt, RoomStatus status, std::vector<Player> players);
    Room(uint32_t id,
         std::string title,
         uint32_t utcTimestampCreatedAt,
         RoomStatus status,
         std::initializer_list<Player> players);
};

struct Event {
    std::string title;
    std::tm *utcTimestampCreatedAt;
    uint32_t numberNight;
    bool isVisible;
    std::vector<Action> prohibits;
    std::vector<Action> allows;

    bool operator<(const Event &other) const;
    bool operator==(const Event &other) const;
    bool operator>(const Event &other) const;

    Event(std::string title,
          uint32_t utcTimestampCreatedAt,
          uint32_t numberNight,
          bool isVisible,
          std::vector<Action> prohibits,
          std::vector<Action> allows);
    Event(std::string title,
          uint32_t utcTimestampCreatedAt,
          uint32_t numberNight,
          bool isVisible,
          std::initializer_list<Action> prohibits,
          std::initializer_list<Action> allows);
};

#endif
