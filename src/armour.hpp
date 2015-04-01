#ifndef _LoX_ARMOUR
#define _LoX_ARMOUR

#include "item.hpp"

struct ArmourTemplate {
    uint type;
    uint limb;
    std::string name;
    uint weight;
    uint AC;
};

enum ArmourLimbs {
    ARMOUR_HELMET,
    ARMOUR_TORSO,
    ARMOUR_LEGS,
    ARMOUR_FEET,
    ARMOUR_HANDS,
    ARMOUR_SHIELD
};

class Armour : public Item {
    uint _limb;
    uint _AC;

public:
    Armour(const ArmourTemplate& at) :
        Item(at.name, ITEM_ARMOUR, at.type, at.weight),
        _limb(at.limb),
        _AC(at.AC)
    {}

    uint Limb() const {return _limb;}
    uint AC() const {return _AC;}
};

#endif
