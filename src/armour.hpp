#ifndef _LoX_ARMOUR
#define _LoX_ARMOUR

enum ArmorTypes {
    ARMOUR_HELMET,
    ARMOUR_TORSO,
    ARMOUR_LEGS,
    ARMOUR_HANDS,
    ARMOUR_FEET,
    ARMOUR_SHIELD
};

class Item_Armour : public Item {
    char _subcat;
    DieRoll _ac;

public:
    char Subcat() const {return _subcat;};
    char AC() const {return _ac.Roll();};
};

#endif
