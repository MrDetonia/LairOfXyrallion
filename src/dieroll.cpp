#include "dieroll.hpp"

std::random_device DieRoll::seed_gen;
unsigned DieRoll::seed = seed_gen();
std::mt19937 DieRoll::mersenne_gen(DieRoll::seed);

uint DieRoll::Roll(uint mod) {
    uint sum = mod;

    for(int i = 0; i < _dieNum; i++) {
        sum += _die(mersenne_gen);
    }

    return sum + _mod;
}
