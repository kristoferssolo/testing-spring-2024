#include "./validation.hh"

#include "modules/room.hh"

#include <algorithm>

bool player_belongs_to_room(Player *player, Room *room) {
    return std::find(room->players.begin(), room->players.end(), *player) != room->players.end();
}

bool action_belongs_to_role(Role *role, const Action *action) {
    return std::find(role->actions.begin(), role->actions.end(), *action) != role->actions.end();
}

bool is_action_allowed(const Action *action, std::vector<Event> *relevantEvents) {
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

int validate_action(
  Player *actor, const Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target = nullptr) {
    if (!actor) {
        return validation::NoActor;
    }
    if (!action) {
        return validation::NoAction;
    }
    if (!room) {
        return validation::NoRoom;
    }
    if (!relatedEvents) {
        return validation::NoRelatedEvents;
    }
    if (!player_belongs_to_room(actor, room)) {
        return validation::PlayerNotInRoom;
    }
    if (action->has_target && !target) {
        return validation::NoTargetPlayerSpecified;
    }
    if (room->status != room::Status::InProgress) {
        return validation::RoomNotInProgress;
    }
    Role *role = &actor->role;
    if (!role) {
        return validation::NoRole;
    }
    if (!action_belongs_to_role(role, action)) {
        return validation::ActionDoesNotBelongToRole;
    }
    if (!is_action_allowed(action, relatedEvents)) {
        return validation::ActionProhibited;
    }
    return validation::ActionProhibited;
}
