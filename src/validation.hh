#pragma once
#include "modules/event.hh"
#include "modules/player.hh"
#include "modules/room.hh"

#include <vector>

enum class ValidationStatus {
    PlayerNotInRoom,
    NoTargetPlayerSpecified,
    RoomNotInProgress,
    ActionDoesNotBelongToRole,
    ActionProhibited,
    NoActor,
    NoAction,
    NoRole,
    NoRoom,
    NoRelatedEvents,
    ActionValid,
};


ValidationStatus
  validate_action(Player *actor, const Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target);
