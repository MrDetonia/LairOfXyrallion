#include "menu_main.hpp"

MenuMain::MenuMain() :
    _menupos(0)
{}

void MenuMain::Update() {
    switch(_ren.GetKey()) {
        /* MENU TRAVERSAL */
        case KEY_UP:
        case 'k':
        case '8':
            if(_menupos > 0) _menupos--;
            break;

        case KEY_DOWN:
        case 'j':
        case '2':
            if(_menupos < MENU_MAIN_ITEM_QUIT) _menupos++;
            break;

        case KEY_ENTER:
        case '\n':
            switch(_menupos) {
                case MENU_MAIN_ITEM_NEW:
                    clear();
                    _state = STATE_GAME;
                    break;

                case MENU_MAIN_ITEM_QUIT:
                    _state = STATE_EXIT;
                    break;
            }
            break;
    }
}

void MenuMain::Draw() {
    /* clear screen first */
    clear();

    /* game title */
    std::string str = "Lair of Xyrallion";
    uchar x = (COLS / 2) - (floor(str.length() / 2));
    uchar y = (LINES / 2) - ((MENU_MAIN_ITEM_QUIT + 3) / 2);
    _ren.Write(str, x, ++y);

    /* new game option */
    str = "Start Game";
    x = (COLS / 2) - (str.length() / 2);
    y += 2;
    if(_menupos == MENU_MAIN_ITEM_NEW) _ren.Write(str, x, y, COL_RED);
    else _ren.Write(str, x, y);

    /* exit game option */
    str = "Quit";
    x = (COLS / 2) - (str.length() / 2);
    if(_menupos == MENU_MAIN_ITEM_QUIT) _ren.Write(str, x, ++y, COL_RED);
    else _ren.Write(str, x, ++y);

    /* game version */
    str = "Development Version ";
    str += _LoX_VERSION;
    _ren.Write(str, 0, LINES-1);

    /* refresh window */
    refresh();
}
