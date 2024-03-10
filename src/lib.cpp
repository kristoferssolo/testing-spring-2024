#include "prep/prep.hh"

#include <vector>

void run() {
    Room room1(1, "Room 1", 1710087364, RoomStatus::IN_PROGRESS);
    Room room2(2, "Room 2", 1710087384, RoomStatus::ENDED);
    Role role1({Action::KILL, Action::HEAL});
    std::vector<Action> actions = {Action::HEAL};
    Role role2(actions);
}

enum VALIDATION_STATUS {
    NO_PLAYER,
    ROOM_NOT_IN_PROGRESS,
    ACTION_PROHIBITED,
    ACTION_NOT_ALLOWED,
    ACTION_VALID,
};

int validateAction(
  Player *actor, Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target = nullptr) {
    return ACTION_VALID;
}

int functionToTest(int a) {
    return a * 2;
}
