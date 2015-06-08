#include "renderer.hpp"

// TODO: make this constructor more robust
Renderer::Renderer() {
    // initialise curses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    // initialise colours if supported by this terminal
    if(has_colors()) {
        start_color();
        init_pair(COL_WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(COL_RED, COLOR_RED, COLOR_BLACK);
        init_pair(COL_GREEN, COLOR_GREEN, COLOR_BLACK);
        init_pair(COL_BLUE, COLOR_BLUE, COLOR_BLACK);
        init_pair(COL_CYAN, COLOR_CYAN, COLOR_BLACK);
        init_pair(COL_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COL_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    }

    /* initialise windows */
    win_map = newwin(LINES - 2, COLS - 18, 0, 0);
    win_msg = newwin(2, COLS, LINES - 2, 0);
    win_stats = newwin(LINES - 2, 18, 0, COLS - 18);
    scrollok(win_msg, TRUE);
    box(win_stats, 0, 0);
    refresh();
}

Renderer::~Renderer() {
    // close curses
    delwin(win_map);
    delwin(win_msg);
    delwin(win_stats);
    endwin();
}

void Renderer::DrawMap(Level& level, Character& player) {
    player.FOV(level);
    ClearMap(level);
    UpdateMap(level, player.Vis());
    DrawCreature(&player);
    wrefresh(win_map);
}

void Renderer::ClearMap(Level& level) {
    for(uint y = 0; y < level.H(); y++) {
        for(uint x = 0; x < level.W(); x++) {
            mvwaddch(win_map, y, x, ' ');
        }
    }
    refresh();
}

void Renderer::UpdateMap(Level& level, std::vector<Vector2D> vis) {
    for(Vector2D &pos: vis) DrawTile(level.Map()[pos.y][pos.x], pos.x, pos.y);
}

void Renderer::DrawTile(Tile& tile, int x, int y) {
    symbol_map _tile = tile_symbols[tile.type];
    wattron(win_map, COLOR_PAIR(_tile.col));
    mvwaddch(win_map, y, x, _tile.sym);
    wattroff(win_map, COLOR_PAIR(_tile.col));

    /* if there are items here, draw the top item of the stack */
    if(!tile.items.empty()) {
        symbol_map item = item_symbols[tile.items[0]->Category()];
        wattron(win_map, COLOR_PAIR(item.col));
        mvwaddch(win_map, y, x, item.sym);
        wattron(win_map, COLOR_PAIR(item.col));
    }
}

void Renderer::DrawCreature(Creature* creature) {
    /* if the object passed is a character, cast to character and display symbol based on race */
    if(creature->Type() == CREATURE_CHARACTER) {
        symbol_map _char = character_symbols[dynamic_cast<Character*>(creature)->Race()];
        wattron(win_map, COLOR_PAIR(_char.col));
        mvwaddch(win_map, creature->Y(), creature->X(), _char.sym);
        wattroff(win_map, COLOR_PAIR(_char.col));
    }
    else {
        symbol_map _creature = creature_symbols[creature->Type()];
        wattron(win_map, COLOR_PAIR(_creature.col));
        mvwaddch(win_map, creature->Y(), creature->X(), _creature.sym);
        wattroff(win_map, COLOR_PAIR(_creature.col));
    }
}

int Renderer::GetKey() {
    return getch();
}

void Renderer::Write(std::string msg, int x, int y, int colour) {
    attron(COLOR_PAIR(colour));
    mvaddstr(y, x, msg.c_str());
    attroff(COLOR_PAIR(colour));
}

void Renderer::Message(std::string msg) {
    scroll(win_msg);
    wattron(win_msg, COLOR_PAIR(COL_WHITE));
    mvwprintw(win_msg, 1, 0, "%s", msg.c_str());
    wattroff(win_msg, COLOR_PAIR(COL_WHITE));
    wrefresh(win_msg);
}

void Renderer::DrawStats(Character player, uchar level) {
    /* display name */
    std::string str = player.Name();
    mvwaddstr(win_stats, 1, 1, str.c_str());

    /* display race */
    switch(player.Race()) {
        case RACE_HUMAN:
            str = "Human";
            break;

        case RACE_ELF:
            str = "Elven";
            break;

        case RACE_DWARF:
            str = "Dwarven";
            break;

        case RACE_HALFLING:
            str = "Halfling";
            break;

        case RACE_GNOME:
            str = "Gnome";
            break;

        case RACE_HALF_ORC:
            str = "Half-Orc";
            break;
    }

    mvwaddstr(win_stats, 2, 1, str.c_str());

    /* display class */
    switch(player.Class()) {
        case CLASS_BARBARIAN:
            str = "Barbarian";
            break;

        case CLASS_BARD:
            str = "Bard";
            break;

        case CLASS_CLERIC:
            str = "Cleric";
            break;

        case CLASS_DRUID:
            str = "Druid";
            break;

        case CLASS_FIGHTER:
            str = "Fighter";
            break;

        case CLASS_MONK:
            str = "Monk";
            break;

        case CLASS_PALADIN:
            str = "Paladin";
            break;

        case CLASS_RANGER:
            str = "Ranger";
            break;

        case CLASS_ROGUE:
            str = "Rogue";
            break;

        case CLASS_SORCEROR:
            str = "Sorceror";
            break;

        case CLASS_WIZARD:
            str = "Wizard";
            break;
    }

    mvwaddstr(win_stats, 3, 1, str.c_str());

    /* display hit points */
    str = "HP:";
    str += std::to_string(player.Hp());
    str += "/";
    str += std::to_string(player.MaxHp());
    mvwaddstr(win_stats, 5, 1, str.c_str());

    /* display mana points */
    str = "MP:";
    str += std::to_string(player.Mp());
    str += "/";
    str += std::to_string(player.MaxMp());
    mvwaddstr(win_stats, 6, 1, str.c_str());

    /* display experience */
    str = "XP:";
    str += std::to_string(player.Xp());
    mvwaddstr(win_stats, 7, 1, str.c_str());

    /* display dungeon level */
    str = "DLvl:";
    str += std::to_string(level+1);
    mvwaddstr(win_stats, 9, 1, str.c_str());

    /* draw window */
    wrefresh(win_stats);
}
