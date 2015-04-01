#ifndef _LoX_ARMOUR
#define _LoX_ARMOUR

#include "item.hpp"

class Armour : public Item {
    uint _limb;
    uint _AC;

public:
    Armour(ArmourTemplate at) :
        Item(at.name, ITEM_ARMOUR, at.type, at.weight),
        _limb(at.limb),
        _AC(at.AC)
    {};

    uint Limb() const {return _limb;};
    uint AC() const {return _AC;};
};

#endif
