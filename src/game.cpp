#include "game.hpp"

Game::Game() :
    _player("Player")
{
    Level tmp(80, 21);
    _dungeon.push_back(tmp);
}

Game::~Game() {
    _dungeon.clear();
}

int Game::Execute() {
    uint level = 0;
    _player.Pos(_dungeon[level].StairUp());

    bool running = true;
    while(running) {
        /* LEVEL DRAWING */
        _player.FOV(_dungeon[level]);
        _renderer.ClearMap(_dungeon[level]);
        _renderer.UpdateMap(_dungeon[level], _player.Vis());
        _renderer.DrawCreature(&_player);

        /* STATUS DRAWING */
        _renderer.DisplayStats(_player);
        std::string msg = "DLvl: " + std::to_string(level + 1) + "  ";
        _renderer.Write(msg, 0, 23);

        /* print items on ground, if any */
        if(_dungeon[level].HasItem(_player.Pos())) {
            std::string msg = "Item here: " + _dungeon[level].SeeItem(_player.Pos())->Name();
            _renderer.Message(msg);
        }

        /* always move cursor back to player when finished drawing */
        move(_player.Pos().y, _player.Pos().x);

        /* KEY INPUT */
        switch(_renderer.GetKey()) {
            /* QUIT GAME */
            case 'q':
                running = false;
                break;

            /* MOVEMENT KEYS */
            case 'k':
            case '8':
                if(_dungeon[level].Map()[_player.Pos().y-1][_player.Pos().x].passable) _player.AddPos(0,-1);
                break;

            case 'j':
            case '2':
                if(_dungeon[level].Map()[_player.Pos().y+1][_player.Pos().x].passable) _player.AddPos(0,1);
                break;

            case 'h':
            case '4':
                if(_dungeon[level].Map()[_player.Pos().y][_player.Pos().x-1].passable) _player.AddPos(-1,0);
                break;

            case 'l':
            case '6':
                if(_dungeon[level].Map()[_player.Pos().y][_player.Pos().x+1].passable) _player.AddPos(1,0);
                break;

            case 'u':
            case '7':
                if(_dungeon[level].Map()[_player.Pos().y-1][_player.Pos().x-1].passable) _player.AddPos(-1,-1);
                break;

            case 'i':
            case '9':
                if(_dungeon[level].Map()[_player.Pos().y-1][_player.Pos().x+1].passable) _player.AddPos(1,-1);
                break;

            case 'n':
            case '1':
                if(_dungeon[level].Map()[_player.Pos().y+1][_player.Pos().x-1].passable) _player.AddPos(-1,1);
                break;

            case 'm':
            case '3':
                if(_dungeon[level].Map()[_player.Pos().y+1][_player.Pos().x+1].passable) _player.AddPos(1,1);
                break;

            /* LEVEL TRAVERSAL */
            case '>':
                if(_player.Pos() == _dungeon[level].StairDown()) {
                    if(_dungeon.size() == ++level) {
                        Level tmp(80, 21);
                        _dungeon.push_back(tmp);
                    }
                    _player.Pos(_dungeon[level].StairUp());
                }
                break;

            case '<':
                if(_player.Pos() == _dungeon[level].StairUp()) {
                    if(level == 0) running = false;
                    else level--;
                    _player.Pos(_dungeon[level].StairDown());
                }
                break;

            /* ITEM MANAGEMENT */
            case ',':
                if(_dungeon[level].HasItem(_player.Pos())) {
                    _inventory.push_back(_dungeon[level].GetItem(_player.Pos()));
                    std::string msg = "Picked up " + _inventory.back()->Name();
                    _renderer.Message(msg);
                }
                break;

            /* DEBUG KEYS */
            case 'r':
                for(Level &level: _dungeon) level.Generate();
                break;
        }
    }

    return 0;
}
