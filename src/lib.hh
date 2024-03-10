#include "prep/prep.hh"

void run();
int validateAction(
  Player *actor, Action *action, Room *room, std::vector<Event> *relatedEvents, Player *target = nullptr);
int functionToTest(int);
