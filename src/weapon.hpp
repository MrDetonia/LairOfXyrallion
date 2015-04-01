#ifndef _LoX_WEAPON
#define _LoX_WEAPON

#include "item.hpp"

class Weapon : public Item{
    uint _style;
    die _dmg;
    uint _crit;

public:
    Weapon(WeaponTemplate wt) :
        Item(wt.name, ITEM_WEAPON, wt.type, wt.weight),
        _style(wt.style),
        _dmg(wt.dmg),
        _crit(wt.crit)
    {};

    uint Style() const {return _style;};
    die Dmg() const {return _dmg;};
    uint Crit() const {return _crit;};
};

#endif
