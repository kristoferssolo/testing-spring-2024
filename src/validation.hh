#ifndef VALIDATION_HH
#define VALIDATION_HH

#include "modules/event.hh"
#include "modules/player.hh"
#include "modules/room.hh"

#include <vector>

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
}  // namespace validation

int validate_action(Player *actor, const Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target);

#endif  // !VALIDATION_HH
