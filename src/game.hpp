#ifndef _LoX_GAME
#define _LoX_GAME

#include "level.hpp"
#include "renderer.hpp"
#include "character.hpp"

class Game {
    std::vector<Level> _dungeon;        // array of dungeons
    Character _player;                  // player character
    std::vector<item_ptr> _inventory;   // player inventory (TODO: Move to character class)
    Renderer _renderer;                 // game renderer

public:
    Game();
    ~Game();

    /* method called to start the game, returns exit status */
    int Execute();
};

#endif
