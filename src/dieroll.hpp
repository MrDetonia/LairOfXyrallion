#ifndef _LoX_DIEROLL
#define _LoX_DIEROLL

#include "common.hpp"

struct Die {uint num; uint val; int mod;};

class DieRoll {
    static std::random_device seed_gen;
    static unsigned seed;
    static std::mt19937 mersenne_gen;

public:
    static uint Roll(Die die={1,20,0});
};

#endif
