#ifndef _LoX_ARMOUR
#define _LoX_ARMOUR

#include "item.hpp"

/* template used to describe armour items */
struct ArmourTemplate {
    uint type;
    uint limb;
    std::string name;
    uint weight;
    uint AC;
};

/* limbs armour can be for */
enum ArmourLimbs {
    ARMOUR_HELMET,
    ARMOUR_TORSO,
    ARMOUR_LEGS,
    ARMOUR_FEET,
    ARMOUR_HANDS,
    ARMOUR_SHIELD
};

class Armour : public Item {
    uint _limb; // what limb this armour is worn on
    uint _AC;   // armour class

public:
    /* constructor takes an ArmourTemplate */
    Armour(const ArmourTemplate& at) :
        Item(at.name, ITEM_ARMOUR, at.type, at.weight),
        _limb(at.limb),
        _AC(at.AC)
    {}

    /* get methods for attributes */
    uint Limb() const {return _limb;}
    uint AC() const {return _AC;}
};

#endif
