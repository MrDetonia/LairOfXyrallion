#ifndef _LoX_FOOD
#define _LoX_FOOD

enum FoodTypes {
    FOOD_RATION,
    FOOD_MEAT_RATION,
    FOOD_CORPSE,
    FOOD_FRUIT
};

class Item_Food : public Item {
    char _subcat;

public:
    char Subcat() {return _subcat;};
};

#endif
