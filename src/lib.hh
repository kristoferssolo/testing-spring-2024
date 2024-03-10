#include "prep/prep.hh"

void run();

bool actionBelongsToRole(Role *role, Action *action);
bool isActionAllowed(Action *action, std::vector<Event> *relevantEvents);
int validateAction(Player *actor, Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target);
int functionToTest(int);
