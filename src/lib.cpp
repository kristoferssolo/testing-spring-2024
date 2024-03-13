#include "lib.hh"

#include "prep/prep.hh"

#include <algorithm>
#include <cstdio>
#include <vector>

enum VALIDATION_STATUS {
    PLAYER_NOT_IN_ROOM,
    NO_TARGET_PLAYER_SPECIFIED,
    ROOM_NOT_IN_PROGRESS,
    ACTION_DOES_NOT_BELONG_TO_ROLE,
    ACTION_PROHIBITED,
    NO_ACTOR,
    NO_ACTION,
    NO_ROLE,
    NO_ROOM,
    NO_RELATED_EVENTS,
    ACTION_VALID,
};

int validateAction(
  Player *actor, const Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target = nullptr) {
    if (!actor) {
        return NO_ACTOR;
    }
    if (!action) {
        return NO_ACTION;
    }
    if (!room) {
        return NO_ROOM;
    }
    if (!relatedEvents) {
        return NO_RELATED_EVENTS;
    }
    if (!playerBelongsToRoom(actor, room)) {
        return PLAYER_NOT_IN_ROOM;
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
        return ACTION_DOES_NOT_BELONG_TO_ROLE;
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
