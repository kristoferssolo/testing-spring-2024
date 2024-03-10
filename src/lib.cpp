#include "lib.hh"

#include "prep/prep.hh"

#include <vector>

enum VALIDATION_STATUS {
    NO_PLAYER,
    ROOM_NOT_IN_PROGRESS,
    ACTION_PROHIBITED,
    ACTION_NOT_ALLOWED,
    NO_ROLE,
    ACTION_VALID,
};

void run() {
    Room room1(1, "Room 1", 1710087364, RoomStatus::IN_PROGRESS);
    Room room2(2, "Room 2", 1710087384, RoomStatus::ENDED);
    const Action kill = Action("kill", true);
    const Action heal = Action("heal", true);
    const Action vote = Action("vote", true);
    Role role1({vote, kill, heal});
    Role role2({heal});
}

int validateAction(
  Player *actor, Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target = nullptr) {
    if (!actor) {
        return NO_PLAYER;
    }
    if (action->hasTarget && !target) {
        return NO_PLAYER;
    }
    if (room->status != RoomStatus::IN_PROGRESS) {
        return ROOM_NOT_IN_PROGRESS;
    }
    Role *role = &actor->role;
    if (!role) {
        return NO_ROLE;
    }
    if (!actionBelongsToRole(role, action)) {
        return ACTION_NOT_ALLOWED;
    }
    if (!isActionAllowed(relatedEvents)) {
        return ACTION_PROHIBITED;
    }
    return ACTION_VALID;
}

bool actionBelongsToRole(Role *role, Action *action) {
    // TODO: implement
    bool belongs = false;
    return belongs;
}

bool isActionAllowed(std::vector<Event> *relevantEvents) {
    // TODO: implement
    bool allowed = false;
    return allowed;
}

int functionToTest(int a) {
    return a * 2;
}
