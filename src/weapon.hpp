#ifndef _LoX_WEAPON
#define _LoX_WEAPON

enum WeaponTypes {
    WEAPON_DAGGER,
    WEAPON_SWORD,
    WEAPON_AXE,
    WEAPON_MACE,
    WEAPON_BOW,
    WEAPON_CROSSBOW,
    WEAPON_STAFF
};

class Item_Weapon : public Item {
    char _subcat;
    DieRoll _damage;
    DieRoll _toHit;

public:
    char Subcat() {return _subcat;};
    int Damage() {return _damage.Roll();};
    int ToHit() {return _toHit.Roll();};
};

#endif
