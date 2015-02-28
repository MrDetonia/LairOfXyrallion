#ifndef _LoX_AMMO
#define _LoX_AMMO

enum AmmoTypes {
    AMMO_ARROW,
    AMMO_BOLT,
    AMMO_ROCK
};

class Item_Ammo : public Item {
    char _subcat;

public:
    char Subcat() {return _subcat;};
};

#endif
