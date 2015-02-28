#ifndef _LoX_SCROLL
#define _LoX_SCROLL

enum ScrollTypes {
    SCROLL_RANDOM,
    SCROLL_IDENTIFY,
    SCROLL_ENCHANT_ARMOUR,
    SCROLL_ENCHANT_WEAPON,
    SCROLL_DESTROY_ARMOUR,
    SCROLL_DESTROY_WEAPON,
    SCROLL_CURSE_ARMOUR,
    SCROLL_CURSE_WEAPON,
    SCROLL_REMOVE_CURSE,
    SCROLL_TELEPORT,
    SCROLL_BLINK,
    SCROLL_MAGIC_MAPPING,
    SCROLL_SUMMON_MONSTER
};

class Item_Scroll : public Item {
    char _subcat;

public:
    char Subcat() {return _subcat;};
};

#endif
