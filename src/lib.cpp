#include "lib.hh"

#include "prep/prep.hh"

void run() {
    Room room1(1, "Room 1", 1710087364, RoomStatus::IN_PROGRESS);
    Room room2(2, "Room 2", 1710087384, RoomStatus::ENDED);
}

int functionToTest(int a) {
    return a * 2;
}
