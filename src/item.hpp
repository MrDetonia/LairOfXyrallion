#ifndef _LoX_ITEM
#define _LoX_ITEM

enum ItemCategories {
    ITEM_GOLD,
    ITEM_ARMOUR,
    ITEM_WEAPON,
    ITEM_AMMO,
    ITEM_POTION,
    ITEM_SCROLL,
    ITEM_WAND,
    ITEM_FOOD,
    ITEM_JEWELLERY
};

enum ItemTypes {
    ITEMTYPE_MUNDANE,
    ITEMTYPE_MAGIC,
    ITEMTYPE_EPIC,
    ITEMTYPE_ARTIFACT,
    ITEMTYPE_PSIONIC
};

class Item {
    char _category;
    char _type;
    char _weight;
    int _value;

public:
    char Category() const {return _category;};
    virtual char Subcat() const {return 255;};
    char Type() const {return _type;};
    char Weight() const {return _weight;};
    int Value() const {return _value;};
};

#endif
