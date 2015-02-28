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

void Renderer::UpdateMap(Level& level) {
    for(int y = 0; y < level.H(); y++) {
        for(int x = 0; x < level.W(); x++) {
            UpdateMap(level.Map()[y][x].type, x, y);
        }
    }
}

void Renderer::UpdateMap(char tile, int x, int y) {
    char symbol;

    switch(tile) {
        case MAP_FLOOR:
            symbol = '.';
            break;

        case MAP_WALL:
            symbol = '#';
            break;

        case MAP_STAIR_UP:
            symbol = '<';
            break;

        case MAP_STAIR_DOWN:
            symbol = '>';
            break;

        default:
            symbol = ' ';
            break;
    }

    mvaddch(y, x, symbol);
}

void Renderer::DrawCreature(Creature creature) {
    char symbol;
    
    switch(creature.Type()) {
        case CREATURE_CHARACTER:
        break;
    }
    
    mvaddch(creature.Pos().y, creature.Pos().x, symbol);
}

void Renderer::DrawCharacter(Character character) {
    char symbol;
    
    switch(character.Race()) {
        case RACE_HUMAN:
            symbol = '@';
            break;
    }
    
    mvaddch(character.Pos().y, character.Pos().x, symbol);
}

int Renderer::GetKey() {
    return getch();
}

void Renderer::Write(std::string msg, int x, int y) {
    mvaddstr(y, x, msg.c_str());
}
