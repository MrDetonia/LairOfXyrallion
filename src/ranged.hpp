#ifndef _LoX_RANGED
#define _LoX_RANGED

#include "item.hpp"

/* template used to describe ranged items */
struct RangedTemplate {
    uint type;
    std::string name;
    uint weight;
    Die dmg;
    uint crit;
    uint range;
};

class Ranged : public Item {
    Die _dmg;       // damage die
    uint _crit;     // critical multiplier
    uint _range;    // range

public:
    /* constructor takes a RangedTemplate */
    Ranged(const RangedTemplate& rt) :
        Item(rt.name, ITEM_RANGED, rt.type, rt.weight),
        _dmg(rt.dmg),
        _crit(rt.crit),
        _range(rt.range)
    {}

    /* get methods for attributes */
    Die Dmg() const {return _dmg;}
    uint Crit() const {return _crit;}
    uint Range() const {return _range;}
};

#endif
