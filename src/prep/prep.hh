#ifndef PREP_H
#define PREP_H

#include <cstdint>
#include <ctime>
#include <string>
#include <vector>

// For test example
int add(int a, int b);

// All IDs are uint32_t
enum EventType {
    PHASE_CHANGE,
    ACTION,
    ROOM_STATE_CHANGE,
    PLAYER_STATE_CHANGE,
};

enum Action {
    KILL,
    VOTE,
    INVESTIGATE,
    HEAL,
    PROTECT,
};

enum RoomStatus {
    AWAITING_START,
    IN_PROGRESS,
    STOPPED,
    ENDED,
};

enum PlayerStatus {
    KICKED,
    ALIVE,
    DEAD,
    VOTED_OUT,
};

struct Role;
struct Player;
struct Room;
struct Event;

struct Role {
    std::vector<Action> actions;
};

struct Player {
    std::string username;
    Role role;
    PlayerStatus playerStatus;
};

struct Room {
    std::string title;
    std::tm *utcTimestampCreatedAt;
    RoomStatus status;
    uint32_t id;
};

struct Event {
    std::string title;
    std::tm *utcTimestampCreatedAt;
    uint32_t numberNight;
    bool isVisible;
    std::vector<Action> causedBy;
    std::vector<Action> influenced;
};

#endif
