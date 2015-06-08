#ifndef _LoX_MENU_MAIN
#define _LoX_MENU_MAIN

#include "common.hpp"
#include "state.hpp"

/* enumeration of items on the main menu */
enum main_menu_items {
    MENU_MAIN_ITEM_NEW = 0,
    MENU_MAIN_ITEM_QUIT
};

class MenuMain : public State {
    uchar _menupos;

public:
    MenuMain();

    /* method used to update the main menu, overrides from base State class */
    void Update();

    /* method used to draw the menu, overrides from base State class */
    void Draw();
};

#endif
