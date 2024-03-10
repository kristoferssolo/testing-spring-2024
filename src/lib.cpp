#include "lib.hh"

#include "prep/prep.hh"

#include <algorithm>
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
    Event event1 = Event("Event 1", 1710087364, 1, true, {vote}, {}, {});
    Event event2 = Event("Event 2", 1710087364, 1, true, {}, {}, {kill});
    Event event3 = Event("Event 3", 1710087364, 1, true, {}, {kill}, {});
    std::vector<Event> relatedEvents({event1, event3});
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
    if (!isActionAllowed(action, relatedEvents)) {
        return ACTION_PROHIBITED;
    }
    return ACTION_VALID;
}

bool actionBelongsToRole(Role *role, Action *action) {
    // TODO: implement
    bool belongs = false;
    return belongs;
}

bool isActionAllowed(Action *action, std::vector<Event> *relevantEvents) {
    // actions are disabled by default
    bool allowed = false;
    std::sort(relevantEvents->begin(), relevantEvents->end());
    for (auto &event : *relevantEvents) {
        if (std::find(event.prohibits.begin(), event.prohibits.end(), *action) != event.prohibits.end()) {
            allowed = false;
        }
        if (std::find(event.allows.begin(), event.allows.end(), *action) != event.allows.end()) {
            allowed = true;
        }
    }
    return allowed;
}

int functionToTest(int a) {
    return a * 2;
}
