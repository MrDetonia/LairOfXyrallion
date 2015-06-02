#ifndef _LoX_CREATURE
#define _LoX_CREATURE

#include "common.hpp"

class Level;

/* enumeration of all available creature types in the game */
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
    uchar _type;                    // type of this creature
    uint _hp;                       // hit points
    uint _max_hp;                   // maximum hit points
    uint _mp;                       // mana points
    uint _max_mp;                   // maximum mana points
    uint _xp;                       // experience points
    Vector2D _pos;                  // coordinates of this creature on map
    std::vector<Vector2D> _vis;     // array of coordinates that this creature can see

    uint _str;  // strength
    uint _dex;  // dexterity
    uint _spd;  // speed
    uint _end;  // endurance
    uint _int;  // intelligence
    uint _wis;  // wisdom
    uint _cha;  // charisma

    /* this function fills _vis with level coordinates visible to this creature */
    void shadowcast(Level& level, uint x, uint y, uint radius, uint row, float start_slope, float end_slope, uint xx, uint xy, uint yx, uint yy);

public:
    /* Creature constructor takes an argument to set the creature type */
    Creature(uchar type);

    /* virtual destructor for Creature class */
    virtual ~Creature() {}

    /* this method adds a vector (in the form of two ints) to _pos */
    void AddPos(int x, int y) {_pos.x += x; _pos.y += y;}

    /* this method explicitally sets _pos */
    void Pos(Vector2D pos) {_pos = pos;}

    /* this method calculates the Field-Of-View for this creature */
    void FOV(Level& level);

    /* get methods for attributes */
    uchar Type() const {return _type;}
    uint Hp() const {return _hp;}
    uint MaxHp() const {return _max_hp;}
    uint Mp() const {return _mp;}
    uint MaxMp() const {return _max_mp;}
    uint Xp() const {return _xp;}
    Vector2D Pos() const {return _pos;}
    uint X() const {return _pos.x;}
    uint Y() const {return _pos.y;}
    std::vector<Vector2D> Vis() const {return _vis;}
    uint Str() const {return _str;}
    uint Dex() const {return _dex;}
    uint Spd() const {return _spd;}
    uint End() const {return _end;}
    uint Int() const {return _int;}
    uint Wis() const {return _wis;}
    uint Cha() const {return _cha;}

    /* VIRTUAL METHODS */

    /*
     * This method is used in the Character class to determine race.
     * It has no use here, so simply returns 255.
     */
    virtual uchar Race() const {return 255;}
};

#endif
