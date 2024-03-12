#include "lib.hh"

#include "prep/prep.hh"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>

enum VALIDATION_STATUS {
    PLAYER_NOT_IN_ROOM,
    NO_PLAYER,
    NO_TARGET_PLAYER_SPECIFIED,
    ROOM_NOT_IN_PROGRESS,
    ACTION_PROHIBITED,
    NO_ROLE,
    ACTION_VALID,
};

void run() {
    const Action kill = Action("kill", true);
    const Action heal = Action("heal", true);
    const Action vote = Action("vote", true);
    Role role1({vote, kill, heal});
    Role role2({heal});
    Event event1 = Event("Event 1", 1710087355, 1, true, {}, {});
    Event event2 = Event("Event 2", 1710087363, 1, true, {kill}, {});
    Event event3 = Event("Event 3", 1710087369, 1, true, {}, {kill});
    std::vector<Event> relatedEvents({event2, event3});
    Player player1 = Player(69, "player1", role1, PlayerStatus::ALIVE);
    Player player2 = Player(420, "player2", role1, PlayerStatus::ALIVE);
    Room room1(1, "Room 1", 1710087364, RoomStatus::IN_PROGRESS, {});
    Room room2(2, "Room 2", 1710087384, RoomStatus::ENDED, {player1, player2});
    int actionValidated = validateAction(&player1, &kill, &room1, &relatedEvents, &player2);
    printf("The action validation result is %u\n", actionValidated);
}

int validateAction(
  Player *actor, const Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target = nullptr) {
    if (!playerBelongsToRoom(actor, room)) {
        return PLAYER_NOT_IN_ROOM;
    }
    if (!actor) {
        return NO_PLAYER;
    }
    if (action->hasTarget && !target) {
        return NO_TARGET_PLAYER_SPECIFIED;
    }
    if (room->status != RoomStatus::IN_PROGRESS) {
        return ROOM_NOT_IN_PROGRESS;
    }
    Role *role = &actor->role;
    if (!role) {
        return NO_ROLE;
    }
    if (!actionBelongsToRole(role, action)) {
        return ACTION_PROHIBITED;
    }
    if (!isActionAllowed(action, relatedEvents)) {
        return ACTION_PROHIBITED;
    }
    return ACTION_VALID;
}

bool playerBelongsToRoom(Player *player, Room *room) {
    return std::find(room->players.begin(), room->players.end(), *player) != room->players.end();
}

bool actionBelongsToRole(Role *role, const Action *action) {
    return std::find(role->actions.begin(), role->actions.end(), *action) != role->actions.end();
}

bool isActionAllowed(const Action *action, std::vector<Event> *relevantEvents) {
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
