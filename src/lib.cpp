#include "lib.hh"

#include "prep/prep.hh"

#include <iostream>

void run() {
    std::cout << add(2, 2) << std::endl;
}

int functionToTest(int a) {
    return a * 2;
}
