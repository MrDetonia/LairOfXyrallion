#ifndef _LoX_POTION
#define _LoX_POTION

enum PotionTypes {
    POTION_WATER,
    POTION_HEAL,
    POTION_CURE,
    POTION_POISON,
    POTION_INVISIBILITY,
    POTION_STRENGTH,
    POTION_DEXTERITY,
    POTION_SPEED,
    POTION_ENDURANCE,
    POTION_INTELLIGENCE,
    POTION_WISDOM,
    POTION_CHARISM
};

class Item_Potion : public Item {
    char _subcat;

public:
    char Subcat() {return _subcat;};
};

#endif
