#include <iostream>
#include "dieRoll.hpp"
#include <cstdlib>
#include <ctime>

int die_roll(int dieNum, int dieMax) {
    int dieMin = 1;
    int total = 0;
    std::srand(std::time(nullptr));
    for (int k = 0; k < dieNum; k++) {
        total += (std::rand() % (dieMax - dieMin + 1) + dieMin);
    }
    return total;
}