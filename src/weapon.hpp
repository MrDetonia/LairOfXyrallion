#ifndef _LoX_WEAPON
#define _LoX_WEAPON

#include "item.hpp"

/* template used to describe weapon items */
struct WeaponTemplate {
    uint type;
    uint style;
    std::string name;
    uint weight;
    Die dmg;
    uint crit;
};

/* all available weapon styles */
enum WeaponStyles {
    WEAPON_SLASHING,
    WEAPON_PIERCING,
    WEAPON_BLUDGEONING
};

class Weapon : public Item {
    uint _style;    // weapon style
    Die _dmg;       // hit die
    uint _crit;     // critical multiplier

public:
    /* constructor takes a WeaponTemplate */
    Weapon(const WeaponTemplate& wt) :
        Item(wt.name, ITEM_WEAPON, wt.type, wt.weight),
        _style(wt.style),
        _dmg(wt.dmg),
        _crit(wt.crit)
    {}

    /* get methods for attributes */
    uint Style() const {return _style;}
    Die Dmg() const {return _dmg;}
    uint Crit() const {return _crit;}
};

#endif
