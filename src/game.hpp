#ifndef _LoX_GAME
#define _LoX_GAME

#include "level.hpp"
#include "renderer.hpp"

class Game {
    std::vector<Level> _dungeon;
    Character _player;
    std::vector<Item*> _inventory;
    Renderer _renderer;

public:
    Game();
    ~Game();

    int Execute();
};

#endif
