#ifndef _LoX_ITEM
#define _LoX_ITEM

#include "common.h"

enum ItemCategories {
    ITEM_ARMOUR,
    ITEM_WEAPON,
    ITEM_AMMO,
    ITEM_POTION,
    ITEM_SCROLL,
    ITEM_WAND,
    ITEM_FOOD
};

enum ItemTypes {
    ITEMTYPE_MUNDANE,
    ITEMTYPE_MAGIC,
    ITEMTYPE_EPIC,
    ITEMTYPE_ARTIFACT,
    ITEMTYPE_PSIONIC
};

class Item {
    std::string _name;
    uint _category;
    uint _type;
    uint _weight;

public:
    uint Category() const {return _category;};
    virtual uint Subcat() const {return 255;};
    uint Type() const {return _type;};
    uint Weight() const {return _weight;};
    int Value() const {return _value;};
};

#endif
