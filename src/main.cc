#include "./validation.hh"

#include <stdlib.h>

int main(int argc, char *argv[]) {
    const Action kill = Action("kill", true);
    const Action heal = Action("heal", true);
    const Action vote = Action("vote", true);
    Role role1({vote, kill, heal});
    Role role2({heal});
    Event event1 = Event("Event 1", 1710087355, 1, true, {}, {});
    Event event2 = Event("Event 2", 1710087363, 1, true, {kill}, {});
    Event event3 = Event("Event 3", 1710087369, 1, true, {}, {kill});
    std::vector<Event> relatedEvents({event2, event3});
    Player player1 = Player(69, "player1", role1, player::Alive);
    Player player2 = Player(420, "player2", role1, player::Alive);
    Room room1(1, "Room 1", 1710087364, room::InProgress, {player1, player2});
    Room room2(2, "Room 2", 1710087384, room::Ended, {});
    int validated_action = validate_action(&player1, &kill, &room1, &relatedEvents, &player2);
    printf("The action validation result is %u\n", validated_action);
    return EXIT_SUCCESS;
}
