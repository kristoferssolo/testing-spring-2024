#include "prep/prep.hh"

#include <vector>

void run() {
    Room room1(1, "Room 1", 1710087364, RoomStatus::IN_PROGRESS);
    Room room2(2, "Room 2", 1710087384, RoomStatus::ENDED);
    Role role1({Action::KILL, Action::HEAL});
    std::vector<Action> actions = {Action::HEAL};
    Role role2(actions);
}

int functionToTest(int a) {
    return a * 2;
}
