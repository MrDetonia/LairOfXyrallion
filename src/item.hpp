#ifndef _LoX_ITEM
#define _LoX_ITEM

#include "common.hpp"

class Armour;
class Weapon;
class Ranged;

enum ItemCategories {
    ITEM_ARMOUR,
    ITEM_WEAPON,
    ITEM_RANGED
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
    Item(std::string name, uint category, uint type, uint weight) :
        _name(name),
        _category(category),
        _type(type),
        _weight(weight)
    {}

    uint Category() const {return _category;}
    uint Type() const {return _type;}
    uint Weight() const {return _weight;}

    static Item* Generate();
};

#endif
