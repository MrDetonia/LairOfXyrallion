#include "renderer.hpp"

// TODO: make this constructor more robust
Renderer::Renderer() {
    // allocate space for screen (std 80x24 terminal)
    _screen = new char* [24];
    for(int i = 0; i < 24; i++) {
        _screen[i] = new char [80];
    }

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
}

Renderer::~Renderer() {
    // close curses
    endwin();

    // free memory used by screen
    for(int i = 0; i < 24; i++) {
        delete [] _screen[i];
    }
    delete [] _screen;
}

void Renderer::ClearMap(Level& level) {
    for(uint y = 0; y < level.H(); y++) {
        for(uint x = 0; x < level.W(); x++) {
            mvaddch(y, x, ' ');
        }
    }
}

void Renderer::UpdateMap(Level& level) {
    for(uint y = 0; y < level.H(); y++) {
        for(uint x = 0; x < level.W(); x++) {
            DrawTile(level.Map()[y][x], x, y);
        }
    }
}

void Renderer::UpdateMap(Level& level, std::vector<Vector2D> vis) {
    for(Vector2D &pos: vis) DrawTile(level.Map()[pos.y][pos.x], pos.x, pos.y);
}

void Renderer::DrawTile(Tile& tile, int x, int y) {
    symbol_map _tile = tile_symbols[tile.type];
    attron(COLOR_PAIR(_tile.col));
    mvaddch(y, x, _tile.sym);
    attroff(COLOR_PAIR(_tile.col));

    /* if there are items here, draw the top item of the stack */
    if(!tile.items.empty()) {
        symbol_map item = item_symbols[tile.items[0]->Category()];
        attron(COLOR_PAIR(item.col));
        mvaddch(y, x, item.sym);
        attron(COLOR_PAIR(item.col));
    }
}

void Renderer::DrawCreature(Creature* creature) {
    /* if the object passed is a character, cast to character and display symbol based on race */
    if(creature->Type() == CREATURE_CHARACTER) {
        symbol_map _char = character_symbols[dynamic_cast<Character*>(creature)->Race()];
        attron(COLOR_PAIR(_char.col));
        mvaddch(creature->Y(), creature->X(), _char.sym);
        attroff(COLOR_PAIR(_char.col));
    }
    else {
        symbol_map _creature = creature_symbols[creature->Type()];
        attron(COLOR_PAIR(_creature.col));
        mvaddch(creature->Y(), creature->X(), _creature.sym);
        attroff(COLOR_PAIR(_creature.col));
    }
}

int Renderer::GetKey() {
    return getch();
}

void Renderer::Write(std::string msg, int x, int y) {
    attron(COLOR_PAIR(COL_WHITE));
    mvaddstr(y, x, msg.c_str());
    attroff(COLOR_PAIR(COL_WHITE));
}

void Renderer::Message(std::string msg) {
    move(21,0);
    clrtoeol();
    attron(COLOR_PAIR(COL_WHITE));
    mvaddstr(21,0,msg.c_str());
    attroff(COLOR_PAIR(COL_WHITE));
}

void Renderer::DisplayStats(Character player) {
    std::string line = player.Name();
    line += " the ";

    switch(player.Race()) {
        case RACE_HUMAN:
            line += "Human";
            break;

        case RACE_ELF:
            line += "Elven";
            break;

        case RACE_DWARF:
            line += "Dwarven";
            break;

        case RACE_HALFLING:
            line += "Halfling";
            break;

        case RACE_GNOME:
            line += "Gnome";
            break;

        case RACE_HALF_ORC:
            line += "Half-Orc";
            break;
    }

    switch(player.Class()) {
        case CLASS_BARBARIAN:
            line += " Barbarian";
            break;

        case CLASS_BARD:
            line += " Bard";
            break;

        case CLASS_CLERIC:
            line += " Cleric";
            break;

        case CLASS_DRUID:
            line += " Druid";
            break;

        case CLASS_FIGHTER:
            line += " Fighter";
            break;

        case CLASS_MONK:
            line += " Monk";
            break;

        case CLASS_PALADIN:
            line += " Paladin";
            break;

        case CLASS_RANGER:
            line += " Ranger";
            break;

        case CLASS_ROGUE:
            line += " Rogue";
            break;

        case CLASS_SORCEROR:
            line += " Sorceror";
            break;

        case CLASS_WIZARD:
            line += " Wizard";
            break;
    }

    line += " HP:";
    line += std::to_string(player.Hp());
    line += "/";
    line += std::to_string(player.MaxHp());
    line += " MP:";
    line += std::to_string(player.Mp());
    line += "/";
    line += std::to_string(player.MaxMp());
    line += " XP:";
    line += std::to_string(player.Xp());

    Write(line, 0, 22);
}
