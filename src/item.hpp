#ifndef _LoX_ITEM
#define _LoX_ITEM

#include "common.hpp"

class Item;

class Armour;
class Weapon;
class Ranged;

typedef std::shared_ptr<Item> item_ptr;

/* enumeration of all item categories in the game */
enum ItemCategories {
    ITEM_ARMOUR,
    ITEM_WEAPON,
    ITEM_RANGED
};

/* enumeration of all item types in the game */
enum ItemTypes {
    ITEMTYPE_MUNDANE,
    ITEMTYPE_MAGIC,
    ITEMTYPE_EPIC,
    ITEMTYPE_ARTIFACT,
    ITEMTYPE_PSIONIC
};

class Item {
    std::string _name;  // name of item
    uint _category;     // item category
    uint _type;         // item type
    uint _weight;       // item weight

public:
    /* constructor takes all of the above attributes as parameters */
    Item(std::string name, uint category, uint type, uint weight) :
        _name(name),
        _category(category),
        _type(type),
        _weight(weight)
    {}

    /* virtual destructor for Item objects */
    virtual ~Item() {}

    /* get methods for attributes */
    std::string Name() const {return _name;}
    uint Category() const {return _category;}
    uint Type() const {return _type;}
    uint Weight() const {return _weight;}

    /* this method generates an item and returns a shared pointer to it */
    static item_ptr Generate();
};

#endif
