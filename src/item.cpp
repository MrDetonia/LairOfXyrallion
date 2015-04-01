#include "item.hpp"

#include "itemlist.hpp"

Item* Item::Generate() {
    Die die = {ITEM_ARMOUR, ITEM_RANGED+1, 0};
    uint cat = DieRoll::Roll(die);

    Item* item;

    switch(cat) {
        case ITEM_ARMOUR:
            die.Set(0, sizeof(armourTemplates)/sizeof(armourTemplates[0]), 0);
            item = new Armour(armourTemplates[DieRoll::Roll(die)]);
            break;

        case ITEM_WEAPON:
            die.Set(0, sizeof(weaponTemplates)/sizeof(weaponTemplates[0]), 0);
            item = new Weapon(weaponTemplates[DieRoll::Roll(die)]);
            break;

        case ITEM_RANGED:
            die.Set(0, sizeof(rangedTemplates)/sizeof(rangedTemplates[0]), 0);
            item = new Ranged(rangedTemplates[DieRoll::Roll(die)]);
            break;

        default:
            item = NULL;
    }

    if(item) return item;
    return NULL;
}
