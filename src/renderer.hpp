#ifndef _LoX_RENDERER
#define _LoX_RENDERER

#include "common.hpp"
#include "level.hpp"

#include <curses.h>

class Renderer {
    char** _screen;

public:
    Renderer();
    ~Renderer();

    void UpdateMap(Level& level);
    void UpdateMap(char tile, int x, int y); 
    void DrawCreature(Creature creature);
    void DrawCharacter(Character character);
    int GetKey();
    void Write(std::string msg, int x, int y);
    void DisplayStats(Character player);
};

#endif
