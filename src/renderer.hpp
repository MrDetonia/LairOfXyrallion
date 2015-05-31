#ifndef _LoX_RENDERER
#define _LoX_RENDERER

#include "common.hpp"
#include "level.hpp"
#include "character.hpp"

#include <curses.h>

class Renderer {
    char** _screen;

public:
    Renderer();
    ~Renderer();

    void ClearMap(Level& level);
    void UpdateMap(Level& level);
    void UpdateMap(Level& level, std::vector<Vector2D> vis);
    void DrawTile(Tile& tile, int x, int y);
    void DrawCreature(Creature* creature);
    int GetKey();
    void Write(std::string msg, int x, int y);
    void Message(std::string msg);
    void DisplayStats(Character player);
    void FOV(Level& level, uint x, uint y, uint radius);
};

struct symbol_map {
    uint type;
    char sym;
};

const symbol_map tile_symbols[] = {
    {MAP_FLOOR, '.'},
    {MAP_WALL, '#'},
    {MAP_STAIR_UP, '<'},
    {MAP_STAIR_DOWN, '>'},
};

const symbol_map item_symbols[] = {
    {ITEM_ARMOUR, '['},
    {ITEM_WEAPON, '('},
    {ITEM_RANGED, '{'},
};

const symbol_map creature_symbols[] = {
    {CREATURE_GOBLIN, 'g'},
};

const symbol_map character_symbols[] = {
    {RACE_HUMAN, '@'},
};

#endif
