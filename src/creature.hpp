#ifndef _LoX_CREATURE
#define _LoX_CREATURE

#include "common.hpp"

enum CreatureTypes {
    CREATURE_CHARACTER,
    CREATURE_BUGBEAR,
    CREATURE_CENTAUR,
    CREATURE_DRAGON,
    CREATURE_DROW_ELF,
    CREATURE_GARGOYLE,
    CREATURE_GIANT,
    CREATURE_GNOLL,
    CREATURE_GOBLIN,
    CREATURE_HOBGOBLIN,
    CREATURE_KOBOLD,
    CREATURE_LIZARD,
    CREATURE_MINOTAUR,
    CREATURE_OGRE,
    CREATURE_OGRE_MAGE,
    CREATURE_ORC,
    CREATURE_RAKSHASA,
    CREATURE_RODENT,
    CREATURE_SATYR,
    CREATURE_TROGLODYTE,
    CREATURE_TROLL,
    CREATURE_UNBODIED
};

class Creature {
    char _type;
    unsigned char _hp;
    unsigned char _max_hp;
    unsigned char _mp;
    unsigned char _max_mp;
    unsigned int _xp;
    Vector2D _pos;

    unsigned char _str;
    unsigned char _dex;
    unsigned char _spd;
    unsigned char _end;
    unsigned char _int;
    unsigned char _wis;
    unsigned char _cha;

public:
    Creature(char type);
    
    void AddPos(int x, int y) {_pos.x += x; _pos.y += y;};
    void Pos(Vector2D pos) {_pos = pos;};
    
    char Type() const {return _type;};
    unsigned char Hp() const {return _hp;};
    unsigned char MaxHp() const {return _max_hp;};
    unsigned char Mp() const {return _mp;};
    unsigned char MaxMp() const {return _max_mp;};
    unsigned char Xp() const {return _xp;};
    Vector2D Pos() const {return _pos;};
    unsigned char Str() const {return _str;};
    unsigned char Dex() const {return _dex;};
    unsigned char Spd() const {return _spd;};
    unsigned char End() const {return _end;};
    unsigned char Int() const {return _int;};
    unsigned char Wis() const {return _wis;};
    unsigned char Cha() const {return _cha;};
};

#endif
