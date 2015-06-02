#include "dieroll.hpp"

std::random_device DieRoll::seed_gen;
unsigned DieRoll::seed = seed_gen();
std::mt19937 DieRoll::mersenne_gen(DieRoll::seed);

uint DieRoll::Roll(Die die) {
    int sum = die.mod;
    std::uniform_int_distribution<uint> rng(1, die.val);
    for(uint i = 0; i < die.num; i++) {
        sum += rng(mersenne_gen);
    }
    if(sum < 0) return 0;
    return (uint)sum;
}
