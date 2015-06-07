#ifndef _LoX_RENDERER
#define _LoX_RENDERER

#include "common.hpp"
#include "level.hpp"
#include "character.hpp"

#include <curses.h>

class Renderer {
    /* game windows */
    WINDOW* win_map;
    WINDOW* win_msg;
    WINDOW* win_stats;

    /* this method clears the map for a level */
    void ClearMap(Level& level);

    /* this method updates only visible parts of the map for a level */
    void UpdateMap(Level& level, std::vector<Vector2D> vis);

    /* this method draws a tile at a specified location */
    void DrawTile(Tile& tile, int x, int y);

    /* this method draws a creature at it's position */
    void DrawCreature(Creature* creature);

public:
    Renderer();
    ~Renderer();

    /* this method handles the draw process for a level */
    void DrawMap(Level& level, Character& player);

    /* this method gets and returns a key press from the user */
    int GetKey();

    /* this method writes a string at a specified location */
    void Write(std::string msg, int x, int y);

    /* this method prints a message in the message area */
    void Message(std::string msg);

    /* this method displays the player's stats in the status area */
    void DrawStats(Character player, uchar level);
};

/* enumeration of colour pairs we register with curses */
enum DrawColours {
    COL_WHITE=1,
    COL_RED,
    COL_GREEN,
    COL_BLUE,
    COL_CYAN,
    COL_YELLOW,
    COL_MAGENTA
};

/* structure used to create symbol maps */
struct symbol_map {
    uint type;
    char sym;
    char col;
};

/* symbol map for map tiles */
const symbol_map tile_symbols[] = {
    {MAP_FLOOR, '.', COL_WHITE},
    {MAP_WALL, '#', COL_WHITE},
    {MAP_STAIR_UP, '<', COL_WHITE},
    {MAP_STAIR_DOWN, '>', COL_WHITE},
};

/* symbol map for items */
const symbol_map item_symbols[] = {
    {ITEM_ARMOUR, '[', COL_RED},
    {ITEM_WEAPON, '(', COL_CYAN},
    {ITEM_RANGED, '{', COL_GREEN},
};

/* symbol map for creatures */
const symbol_map creature_symbols[] = {
    {CREATURE_BUGBEAR, 'b', COL_YELLOW},
    {CREATURE_CENTAUR, 'c', COL_MAGENTA},
    {CREATURE_DRAGON, 'D', COL_RED},
    {CREATURE_DROW_ELF, 'E', COL_MAGENTA},
    {CREATURE_GARGOYLE, 'G', COL_BLUE},
    {CREATURE_GIANT, 'G', COL_GREEN},
    {CREATURE_GNOLL, 'g', COL_YELLOW},
    {CREATURE_GOBLIN, 'g', COL_GREEN},
    {CREATURE_HOBGOBLIN, 'g', COL_RED},
    {CREATURE_KOBOLD, 'k', COL_CYAN},
    {CREATURE_LIZARD, 'l', COL_GREEN},
    {CREATURE_MINOTAUR, 'M', COL_RED},
    {CREATURE_OGRE, 'O', COL_BLUE},
    {CREATURE_OGRE_MAGE, 'O', COL_MAGENTA},
    {CREATURE_ORC, 'o', COL_RED},
    {CREATURE_RAKSHASA, 'R', COL_BLUE},
    {CREATURE_RODENT, 'r', COL_YELLOW},
    {CREATURE_SATYR, 'S', COL_CYAN},
    {CREATURE_TROGLODYTE, 't', COL_WHITE},
    {CREATURE_TROLL, 'T', COL_RED},
    {CREATURE_UNBODIED, 'z', COL_WHITE},
};

/* symbol map for characters/races */
const symbol_map character_symbols[] = {
    {RACE_HUMAN, '@', COL_WHITE},
    {RACE_ELF, 'E', COL_WHITE},
    {RACE_DWARF, 'd', COL_WHITE},
    {RACE_HALFLING, 'h', COL_WHITE},
    {RACE_GNOME, 'g', COL_WHITE},
    {RACE_HALF_ORC, 'o', COL_WHITE},
};

#endif
