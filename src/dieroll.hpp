#ifndef _LoX_DIEROLL
#define _LoX_DIEROLL

#include "common.hpp"

struct Die {
    uint num;
    uint val;
    int mod;
};

class DieRoll {
    static std::random_device seed_gen;
    static unsigned seed;
    static std::mt19937 mersenne_gen;

    uint _dieNum;
    std::uniform_int_distribution<uint> _die;
    uint _mod;

public:
    DieRoll(uint dieNum=1, uint dieVal=20, uint mod=0) :
        _dieNum(dieNum),
        _mod(mod)
    {
        std::uniform_int_distribution<uint> tmp(1, dieVal);
        _die = tmp;
    };

    uint Roll(uint mod=0);
};

#endif
