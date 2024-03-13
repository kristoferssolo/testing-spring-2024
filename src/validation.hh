#ifndef VALIDATION_HH
#define VALIDATION_HH

#include "event.hh"
#include "player.hh"
#include "room.hh"

namespace validation {
    enum Status {
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
}

int validateAction(Player *actor, const Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target);

#endif  // !VALIDATION_HH
