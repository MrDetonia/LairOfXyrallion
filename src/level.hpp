#ifndef _LoX_LEVEL
#define _LoX_LEVEL

#include "common.hpp"
#include "character.hpp"
#include "item.hpp"

#include <ctime>
#include <vector>

struct Tile {
    char type;
    bool passable;
    bool visible;
};

enum MapTiles {
    MAP_FLOOR = 0,
    MAP_WALL,
    MAP_STAIR_UP,
    MAP_STAIR_DOWN
};

const Tile tiles[] = {
    {MAP_FLOOR, true, false},
    {MAP_WALL, false, false},
    {MAP_STAIR_UP, true, false},
    {MAP_STAIR_DOWN, true, false}
};

class Level {
    Tile** _map;
    Vector2D _stairDown, _stairUp;
    std::vector<Creature*> _creatures;
    std::vector<Item*> _items;
    char _w;
    char _h;
    int _fillprob;
    int _r1_cutoff, _r2_cutoff;
    int _passes;

    int randpick();

public:
    Level(char w = 80, char h = 24, int fillprob = 40, int r1_cutoff = 5, int r2_cutoff = 0, int passes = 12) :
        _w(w),
        _h(h),
        _fillprob(fillprob),
        _r1_cutoff(r1_cutoff),
        _r2_cutoff(r2_cutoff),
        _passes(passes)
    {
        // allocate memory for map
        _map = new Tile* [_h];
        for(int i = 0; i < _h; i++) {
            _map[i] = new Tile [_w];
        }

        // generate level
        this->Generate();
    };

    Level(const Level& o) {
        // copy old variables
        _w = o._w;
        _h = o._h;
        _fillprob = o._fillprob;
        _r1_cutoff = o._r1_cutoff;
        _r2_cutoff = o._r2_cutoff;
        _passes = o._passes;

        // allocate memory for new map
        _map = new Tile* [_h];
        for(int i = 0; i < _h; i++) {
            _map[i] = new Tile [_w];
        }

        // generate level
        this->Generate();
    }

    ~Level() {
        for(int i = 0; i < _h; i++) {
            delete [] _map[i];
        }
        delete [] _map;
    }

    void Generate();
    Tile** Map() const {return _map;};
    Vector2D StairDown() const {return _stairDown;};
    Vector2D StairUp() const {return _stairUp;};
    char W() const {return _w;};
    char H() const {return _h;};
};

#endif
