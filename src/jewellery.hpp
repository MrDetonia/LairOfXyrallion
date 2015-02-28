#ifndef _LoX_JEWELLERY
#define _LoX_JEWELLERY

enum JewelleryTypes {
    RING_INVISIBILITY,
    RING_SEE_INVISIBLE,
    RING_PROTECTION,
    RING_TELEPORTATION
};

class Item_Jewellery : public Item {
    char _subcat;

public:
    char Subcat() {return _subcat;};
};

#endif
