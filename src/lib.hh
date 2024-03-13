#include "action.hh"
#include "prep/prep.hh"

bool playerBelongsToRoom(Player *player, Room *room);
bool actionBelongsToRole(Role *role, const Action *action);
bool isActionAllowed(const Action *action, std::vector<Event> *relevantEvents);
int validateAction(Player *actor, const Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target);
