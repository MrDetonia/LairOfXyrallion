#ifndef _LoX_DIEROLL
#define _LoX_DIEROLL

#include "common.hpp"

class DieRoll {
    static std::random_device seed_gen;
    static unsigned seed;
    static std::mt19937 mersenne_gen;

    char _dieNum;
    std::uniform_int_distribution<int> _die;
    char _mod;

public:
    DieRoll(char dieNum=1, char dieVal=20, char mod=0) :
        _dieNum(dieNum),
        _mod(mod)
    {
        std::uniform_int_distribution<int> tmp(1, dieVal);
        _die = tmp;
    };

    int Roll(char mod=0);
};

#endif
