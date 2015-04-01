#ifndef _LoX_WEAPON
#define _LoX_WEAPON

#include "item.hpp"

struct WeaponTemplate {
    uint type;
    uint style;
    std::string name;
    uint weight;
    Die dmg;
    uint crit;
};

enum WeaponStyles {
    WEAPON_SLASHING,
    WEAPON_PIERCING,
    WEAPON_BLUDGEONING
};

class Weapon : public Item {
    uint _style;
    Die _dmg;
    uint _crit;

public:
    Weapon(const WeaponTemplate& wt) :
        Item(wt.name, ITEM_WEAPON, wt.type, wt.weight),
        _style(wt.style),
        _dmg(wt.dmg),
        _crit(wt.crit)
    {}

    uint Style() const {return _style;}
    Die Dmg() const {return _dmg;}
    uint Crit() const {return _crit;}
};

#endif
