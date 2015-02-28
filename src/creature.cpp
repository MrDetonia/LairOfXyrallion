#include "creature.hpp"

Creature::Creature(char type) {
    // TODO: Add generation for stats depending on type
    _type = type;
    _hp = _max_hp = 8;
    _mp = _max_mp = 8;
    _xp = 0;
    _pos = {0,0};
    _str = 8;
    _dex = 8;
    _spd = 8;
    _end = 8;
    _int = 8;
    _wis = 8;
    _cha = 8;
}