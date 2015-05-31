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
    mvaddch(y, x, tile_symbols[tile.type].sym);

    /* if there are items here, draw the top item of the stack */
    if(!tile.items.empty()) mvaddch(y, x, item_symbols[tile.items[0]->Category()].sym);
}

void Renderer::DrawCreature(Creature* creature) {
    /* if the object passed is a character, cast to character and display symbol based on race */
    if(creature->Type() == CREATURE_CHARACTER) {
        mvaddch(creature->Y(), creature->X(), character_symbols[dynamic_cast<Character*>(creature)->Race()].sym);
    }
    else {
        mvaddch(creature->Y(), creature->X(), creature_symbols[creature->Type()].sym);
    }
}

int Renderer::GetKey() {
    return getch();
}

void Renderer::Write(std::string msg, int x, int y) {
    mvaddstr(y, x, msg.c_str());
}

void Renderer::Message(std::string msg) {
    move(21,0);
    clrtoeol();
    mvaddstr(21,0,msg.c_str());
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

        case RACE_DROMITE:
            line += "Dromite";
            break;

        case RACE_DUERGAR:
            line += "Duergar";
            break;

        case RACE_ELAN:
            line += "Elan";
            break;

        case RACE_HALF_GIANT:
            line += "Half-Giant";
            break;

        case RACE_MAENAD:
            line += "Maenad";
            break;

        case RACE_XEPH:
            line += "Xeph";
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

        case CLASS_PSION:
            line += " Psion";
            break;

        case CLASS_PSYCHIC_WARRIOR:
            line += " Psychic Warrior";
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

        case CLASS_SOULKNIFE:
            line += " Soulknife";
            break;

        case CLASS_WILDER:
            line += " Wilder";
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

    mvaddstr(22, 0, line.c_str());
}
