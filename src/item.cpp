#include "item.hpp"

#include "itemlist.hpp"

item_ptr Item::Generate() {
    Die die = {1, ITEM_RANGED + 1, -1};
    uint cat = DieRoll::Roll(die);

    item_ptr item;

    switch(cat) {
        case ITEM_ARMOUR:
            die.Set(1, sizeof(armourTemplates)/sizeof(armourTemplates[0]), -1);
            item = std::make_shared<Armour>(armourTemplates[DieRoll::Roll(die)]);
            break;

        case ITEM_WEAPON:
            die.Set(1, sizeof(weaponTemplates)/sizeof(weaponTemplates[0]), -1);
            item = std::make_shared<Weapon>(weaponTemplates[DieRoll::Roll(die)]);
            break;

        case ITEM_RANGED:
            die.Set(1, sizeof(rangedTemplates)/sizeof(rangedTemplates[0]), -1);
            item = std::make_shared<Ranged>(rangedTemplates[DieRoll::Roll(die)]);
            break;

        default:
            item = std::make_shared<Item>("Nothing", 255, 255, 0);
    }

    return item;
}
