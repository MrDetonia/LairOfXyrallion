#include "game.hpp"

Game::Game() :
    _player("Player")
{
    Level tmp(LEVEL_WIDTH, LEVEL_HEIGHT);
    _dungeon.push_back(tmp);
    _level = 0;
    _player.Pos(_dungeon[_level].StairUp());
}

Game::~Game() {
    _dungeon.clear();
}

void Game::Draw() {
    /* LEVEL DRAWING */
    _ren.DrawMap(_dungeon[_level], _player);

    /* STATUS DRAWING */
    _ren.DrawStats(_player, _level);

    /* print items on ground, if any */
    if(_dungeon[_level].HasItem(_player.Pos())) {
        std::string msg = "Item here: " + _dungeon[_level].SeeItem(_player.Pos())->Name();
        _ren.Message(msg);
    }

    /* always move cursor back to player when finished drawing */
    move(_player.Y(), _player.X());
}

void Game::Update() {
    /* KEY INPUT */
    switch(_ren.GetKey()) {
        /* QUIT GAME */
        case 'q':
            _state = STATE_EXIT;
            break;

        /* MOVEMENT KEYS */
        case 'k':
        case '8':
            if(_dungeon[_level].Map()[_player.Y()-1][_player.X()].passable) _player.AddPos(0,-1);
            break;

        case 'j':
        case '2':
            if(_dungeon[_level].Map()[_player.Y()+1][_player.X()].passable) _player.AddPos(0,1);
            break;

        case 'h':
        case '4':
            if(_dungeon[_level].Map()[_player.Y()][_player.X()-1].passable) _player.AddPos(-1,0);
            break;

        case 'l':
        case '6':
            if(_dungeon[_level].Map()[_player.Y()][_player.X()+1].passable) _player.AddPos(1,0);
            break;

        case 'u':
        case '7':
            if(_dungeon[_level].Map()[_player.Y()-1][_player.X()-1].passable) _player.AddPos(-1,-1);
            break;

        case 'i':
        case '9':
            if(_dungeon[_level].Map()[_player.Y()-1][_player.X()+1].passable) _player.AddPos(1,-1);
            break;

        case 'n':
        case '1':
            if(_dungeon[_level].Map()[_player.Y()+1][_player.X()-1].passable) _player.AddPos(-1,1);
            break;

        case 'm':
        case '3':
            if(_dungeon[_level].Map()[_player.Y()+1][_player.X()+1].passable) _player.AddPos(1,1);
            break;

        /* LEVEL TRAVERSAL */
        case '>':
            if(_player.Pos() == _dungeon[_level].StairDown()) {
                if(_dungeon.size() == ++_level) {
                    Level tmp(LEVEL_WIDTH, LEVEL_HEIGHT);
                    _dungeon.push_back(tmp);
                }
                _player.Pos(_dungeon[_level].StairUp());
            }
            break;

        case '<':
            if(_player.Pos() == _dungeon[_level].StairUp()) {
                if(_level == 0) _state = STATE_EXIT;
                else _level--;
                _player.Pos(_dungeon[_level].StairDown());
            }
            break;

        /* ITEM MANAGEMENT */
        case ',':
            if(_dungeon[_level].HasItem(_player.Pos())) {
                _inventory.push_back(_dungeon[_level].GetItem(_player.Pos()));
                std::string msg = "Picked up " + _inventory.back()->Name();
                _ren.Message(msg);
            }
            break;

        /* DEBUG KEYS */
        case 'r':
            for(Level &level: _dungeon) level.Generate();
            break;
    }
}
