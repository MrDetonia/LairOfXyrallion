#ifndef _LoX_WAND
#define _LoX_WAND

enum WandTypes {
    WAND_MAGIC_MISSILE,
    WAND_LIGHT,
    WAND_POLYMORPH,
    WAND_DIGGING
};

class Item_Wand : public Item {
    char _subcat;

public:
    char Subcat() {return _subcat;};
};

#endif
