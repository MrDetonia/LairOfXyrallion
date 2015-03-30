#ifndef _LoX_CREATURE
#define _LoX_CREATURE

#include "common.hpp"

class Level;

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
    uint _hp;
    uint _max_hp;
    uint _mp;
    uint _max_mp;
    uint _xp;
    Vector2D _pos;
    std::vector<Vector2D> _vis;

    uint _str;
    uint _dex;
    uint _spd;
    uint _end;
    uint _int;
    uint _wis;
    uint _cha;

    void shadowcast(Level& level, uint x, uint y, uint radius, uint row, float start_slope, float end_slope, uint xx, uint xy, uint yx, uint yy);

public:
    Creature(char type);

    void AddPos(int x, int y) {_pos.x += x; _pos.y += y;};
    void Pos(Vector2D pos) {_pos = pos;};
    std::vector<Vector2D> Vis() const {return _vis;};
    void FOV(Level& level);

    char Type() const {return _type;};
    uint Hp() const {return _hp;};
    uint MaxHp() const {return _max_hp;};
    uint Mp() const {return _mp;};
    uint MaxMp() const {return _max_mp;};
    uint Xp() const {return _xp;};
    Vector2D Pos() const {return _pos;};
    uint Str() const {return _str;};
    uint Dex() const {return _dex;};
    uint Spd() const {return _spd;};
    uint End() const {return _end;};
    uint Int() const {return _int;};
    uint Wis() const {return _wis;};
    uint Cha() const {return _cha;};
};

#endif
