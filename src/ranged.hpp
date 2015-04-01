#ifndef _LoX_RANGED
#define _LoX_RANGED

#include "item.hpp"

class Ranged : public Item {
    die _dmg;
    uint _crit;
    uint _range;

public:
    Ranged(RangedTemplate rt) :
        Item(rt.name, ITEM_RANGED, rt.type, rt.weight),
        _dmg(rt.dmg),
        _crit(rt.crit),
        _range(rt.range)
    {};

    die Dmg() const {return _dmg;};
    uint Crit() const {return _crit;};
    uint Range() const {return _range;};
};

#endif
