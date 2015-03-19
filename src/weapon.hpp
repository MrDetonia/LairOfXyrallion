#ifndef _LoX_WEAPON
#define _LoX_WEAPON

enum WeaponTypes {
    WEAPON_SLASHING,
    WEAPON_PIERCING,
    WEAPON_BLUDGEONING,
    WEAPON_RANGED
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
