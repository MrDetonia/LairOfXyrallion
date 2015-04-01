#ifndef _LoX_ITEMLIST
#define _LoX_ITEMLIST

#include "common.hpp"

struct ArmourTemplate {
    uint type;
    uint limb;
    std::string name;
    uint weight;
    uint AC;
};

struct WeponTemplate {
    uint type;
    uint style;
    std::string name;
    uint weight;
    die dmg;
    uint crit;
};

struct RangedTemplate {
    uint type;
    std::string name;
    uint weight;
    die dmg;
    uint crit;
    uint range;
};

const ArmourTemplate armourTemplates[] = {
    /* ARMOUR_HELMET */
    {ITEMTYPE_MUNDANE, ARMOUR_HELMET, "Leather Helmet", 5, 1},
    {ITEMTYPE_MUNDANE, ARMOUR_HELMET, "Hide Helmet", 10, 2},
    {ITEMTYPE_MUNDANE, ARMOUR_HELMET, "Steel Helmet", 20, 4},
    {ITEMTYPE_MUNDANE, ARMOUR_HELMET, "Dwarven Helmet", 25, 6},
    {ITEMTYPE_MAGIC, ARMOUR_HELMET, "Elven Helmet", 10, 6},
    {ITEMTYPE_EPIC, ARMOUR_HELMET, "Draconian Helmet", 45, 8},

    /* ARMOUR_TORSO */
    {ITEMTYPE_MUNDANE, ARMOUR_TORSO, "Leather Armour", 15, 2},
    {ITEMTYPE_MUNDANE, ARMOUR_TORSO, "Hide Armour", 25, 3},
    {ITEMTYPE_MUNDANE, ARMOUR_TORSO, "Steel Armour", 50, 7},
    {ITEMTYPE_MUNDANE, ARMOUR_TORSO, "Dwarven Armour", 55, 8},
    {ITEMTYPE_MAGIC, ARMOUR_TORSO, "Elven Armour", 25, 8},
    {ITEMTYPE_EPIC, ARMOUR_TORSO, "Draconian Armour", 75, 10},

    /* ARMOUR_LEGS */
    {ITEMTYPE_MUNDANE, ARMOUR_LEGS, "Leather Greaves", 10, 1},
    {ITEMTYPE_MUNDANE, ARMOUR_LEGS, "Hide Greaves", 15, 2},
    {ITEMTYPE_MUNDANE, ARMOUR_LEGS, "Steel Greaves", 25, 5},
    {ITEMTYPE_MUNDANE, ARMOUR_LEGS, "Dwarven Greaves", 35, 6},
    {ITEMTYPE_MAGIC, ARMOUR_LEGS, "Elven Greaves", 15, 6},
    {ITEMTYPE_EPIC, ARMOUR_LEGS, "Draconian Greaves", 55, 8},

    /* ARMOUR_HANDS */
    {ITEMTYPE_MUNDANE, ARMOUR_HANDS, "Leather Gloves", 2, 1},
    {ITEMTYPE_MUNDANE, ARMOUR_HANDS, "Hide Gloves", 5, 2},
    {ITEMTYPE_MUNDANE, ARMOUR_HANDS, "Steel Gloves", 10, 3},
    {ITEMTYPE_MUNDANE, ARMOUR_HANDS, "Dwarven Gloves", 20, 4},
    {ITEMTYPE_MAGIC, ARMOUR_HANDS, "Elven Gloves", 5, 4},
    {ITEMTYPE_EPIC, ARMOUR_HANDS, "Draconian Gloves", 40, 6},

    /* ARMOUR_FEET */
    {ITEMTYPE_MUNDANE, ARMOUR_FEET, "Leather Boots", 2, 1},
    {ITEMTYPE_MUNDANE, ARMOUR_FEET, "Hide Boots", 5, 2},
    {ITEMTYPE_MUNDANE, ARMOUR_FEET, "Steel Boots", 10, 3},
    {ITEMTYPE_MUNDANE, ARMOUR_FEET, "Dwarven Boots", 20, 4},
    {ITEMTYPE_MAGIC, ARMOUR_FEET, "Elven Boots", 5, 4},
    {ITEMTYPE_EPIC, ARMOUR_FEET, "Draconian Boots", 40, 6},

    /* ARMOUR_SHIELD */
    {ITEMTYPE_MUNDANE, ARMOUR_SHIELD, "Leather Shield", 12, 2},
    {ITEMTYPE_MUNDANE, ARMOUR_SHIELD, "Hide Shield", 17, 3},
    {ITEMTYPE_MUNDANE, ARMOUR_SHIELD, "Steel Shield", 27, 7},
    {ITEMTYPE_MUNDANE, ARMOUR_SHIELD, "Dwarven Shield", 37, 8},
    {ITEMTYPE_MAGIC, ARMOUR_SHIELD, "Elven Shield", 17, 3},
    {ITEMTYPE_EPIC, ARMOUR_SHIELD, "Draconian Shield", 57, 10},
};

const WeaponTemplate weaponTemplates[] = {
    /* WEAPON_SLASHING */
    {ITEMTYPE_MUNDANE, WEAPON_SLASHING, "Iron Dagger", 1, {1,4,0}, 2},
    {ITEMTYPE_MUNDANE, WEAPON_SLASHING, "Iron Sword", 2, {1,6,0}, 2},
    {ITEMTYPE_MUNDANE, WEAPON_SLASHING, "Iron Waraxe", 3, {1,6,0}, 3},
    {ITEMTYPE_MUNDANE, WEAPON_SLASHING, "Steel Dagger", 2, {1,4,2}, 2},
    {ITEMTYPE_MUNDANE, WEAPON_SLASHING, "Steel Sword", 3, {1,6,2}, 2},
    {ITEMTYPE_MUNDANE, WEAPON_SLASHING, "Steel Waraxe", 4, {1,6,2}, 3},
    {ITEMTYPE_MAGIC, WEAPON_SLASHING, "Silver Dagger", 2, {1,4,3}, 2},
    {ITEMTYPE_MAGIC, WEAPON_SLASHING, "Silver Sword", 3, {1,6,3}, 2},
    {ITEMTYPE_MAGIC, WEAPON_SLASHING, "Silver Waraxe", 4, {1,6,3}, 3},
    {ITEMTYPE_MAGIC, WEAPON_SLASHING, "Elven Dagger", 1, {1,4,6}, 2},
    {ITEMTYPE_MAGIC, WEAPON_SLASHING, "Elven Sword", 2, {1,6,6}, 2},
    {ITEMTYPE_MAGIC, WEAPON_SLASHING, "Elven Waraxe", 3, {1,6,6}, 3},
    {ITEMTYPE_EPIC, WEAPON_SLASHING, "Draconian Dagger", 4, {1,4,10}, 3},
    {ITEMTYPE_EPIC, WEAPON_SLASHING, "Draconian Sword", 5, {1,6,10}, 3},
    {ITEMTYPE_EPIC, WEAPON_SLASHING, "Draconian Waraxe", 6, {1,6,10}, 4},

    /* WEAPON_PIERCING */
    {ITEMTYPE_MUNDANE, WEAPON_PIERCING, "Iron Spear", 3, {1,8,0}, 3},
    {ITEMTYPE_MUNDANE, WEAPON_PIERCING, "Iron Pick", 6, {1,6,0}, 4},
    {ITEMTYPE_MUNDANE, WEAPON_PIERCING, "Iron Rapier", 2, {1,6,0}, 2},
    {ITEMTYPE_MUNDANE, WEAPON_PIERCING, "Steel Spear", 4, {1,8,2}, 3},
    {ITEMTYPE_MUNDANE, WEAPON_PIERCING, "Steel Pick", 7, {1,6,2}, 4},
    {ITEMTYPE_MUNDANE, WEAPON_PIERCING, "Steel Rapier", 3, {1,6,2}, 2},
    {ITEMTYPE_MAGIC, WEAPON_PIERCING, "Silver Spear", 4, {1,8,3}, 3},
    {ITEMTYPE_MAGIC, WEAPON_PIERCING, "Silver Pick", 7, {1,6,3}, 4},
    {ITEMTYPE_MAGIC, WEAPON_PIERCING, "Silver Rapier", 3, {1,6,3}, 2},
    {ITEMTYPE_MAGIC, WEAPON_PIERCING, "Elven Spear", 3, {1,8,6}, 3},
    {ITEMTYPE_MAGIC, WEAPON_PIERCING, "Elven Pick", 6, {1,6,6}, 4},
    {ITEMTYPE_MAGIC, WEAPON_PIERCING, "Elven Rapier", 2, {1,6,6}, 2},
    {ITEMTYPE_EPIC, WEAPON_PIERCING, "Draconian Spear", 6, {1,8,10}, 4},
    {ITEMTYPE_EPIC WEAPON_PIERCING, "Draconian Pick", 9, {1,6,10}, 5},
    {ITEMTYPE_EPIC, WEAPON_PIERCING, "Draconian Rapier", 5, {1,6,10}, 3},

    /* WEAPON_BLUDGEONING */
    {ITEMTYPE_MUNDANE, WEAPON_BLUDGEONING, "Iron Club", 3, {1,6,0}, 2},
    {ITEMTYPE_MUNDANE, WEAPON_BLUDGEONING, "Iron Mace", 6, {1,8,0}, 2},
    {ITEMTYPE_MUNDANE, WEAPON_BLUDGEONING, "Iron Warhammer", 5, {1,8,0}, 3},
    {ITEMTYPE_MUNDANE, WEAPON_BLUDGEONING, "Steel Club", 4, {1,6,2}, 2},
    {ITEMTYPE_MUNDANE, WEAPON_BLUDGEONING, "Steel Mace", 7, {1,8,2}, 2},
    {ITEMTYPE_MUNDANE, WEAPON_BLUDGEONING, "Steel Warhammer", 6, {1,8,2}, 3},
    {ITEMTYPE_MAGIC, WEAPON_BLUDGEONING, "Silver Club", 4, {1,6,3}, 2},
    {ITEMTYPE_MAGIC, WEAPON_BLUDGEONING, "Silver Mace", 7, {1,8,3}, 2},
    {ITEMTYPE_MAGIC, WEAPON_BLUDGEONING, "Silver Warhammer", 6, {1,8,3}, 3},
    {ITEMTYPE_MAGIC, WEAPON_BLUDGEONING, "Elven Club", 3, {1,6,6}, 2},
    {ITEMTYPE_MAGIC, WEAPON_BLUDGEONING, "Elven Mace", 6, {1,8,6}, 2},
    {ITEMTYPE_MAGIC, WEAPON_BLUDGEONING, "Elven Warhammer", 5, {1,8,6}, 3},
    {ITEMTYPE_EPIC, WEAPON_BLUDGEONING, "Draconian Club", 6, {1,6,10}, 3},
    {ITEMTYPE_EPIC, WEAPON_BLUDGEONING, "Draconian Mace", 9, {1,8,10}, 3},
    {ITEMTYPE_EPIC, WEAPON_BLUDGEONING, "Draconian Warhammer", 8, {1,8,10}, 4},
};

const RangedTemplate rangedTemplates[] = {
    {ITEMTYPE_MUNDANE, WEAPON_RANGED, "Crossbow", 4, {1,8,0}, 2, 8},
    {ITEMTYPE_MUNDANE, WEAPON_RANGED, "Shortbow", 2, {1,6,0}, 3, 6},
    {ITEMTYPE_MUNDANE, WEAPON_RANGED, "Longbow", 3, {1,8,0}, 3, 10},
    {ITEMTYPE_MAGIC, WEAPON_RANGED, "Elven Crossbow", 3, {1,8,3}, 2, 8},
    {ITEMTYPE_MAGIC, WEAPON_RANGED, "Elven Shortbow", 1, {1,6,3}, 3, 6},
    {ITEMTYPE_MAGIC, WEAPON_RANGED, "Elven Longbow", 2, {1,8,3}, 3, 10},
    {ITEMTYPE_EPIC, WEAPON_RANGED, "Draconian Crossbow", 6, {1,8,8}, 3, 8},
    {ITEMTYPE_EPIC, WEAPON_RANGED, "Draconian Shortbow", 4, {1,6,8}, 4, 6},
    {ITEMTYPE_EPIC, WEAPON_RANGED, "Draconian Longbow", 5, {1,8,8}, 4, 10},
};

#endif
