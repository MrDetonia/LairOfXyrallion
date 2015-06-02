#ifndef _LoX_LEVEL
#define _LoX_LEVEL

#include "common.hpp"

#include "item.hpp"

#include <ctime>
#include <vector>

class Creature;
class Character;

/* structure used to store information about tiles in a level */
struct Tile {
    std::vector<item_ptr> items;    // array of items on this tile
    uchar type;                     // type of tile
    bool passable;                  // if this tile is passable by creatures
    bool opaque;                    // if this tile blocks vision
};

/* enumeration of all map tiles in the game */
enum MapTiles {
    MAP_FLOOR = 0,
    MAP_WALL,
    MAP_STAIR_UP,
    MAP_STAIR_DOWN
};

/* lookup table for all map tiles in the game */
const Tile tiles[] = {
    {{}, MAP_FLOOR, true, false},
    {{}, MAP_WALL, false, true},
    {{}, MAP_STAIR_UP, true, false},
    {{}, MAP_STAIR_DOWN, true, false}
};

class Level {
    Tile** _map;                        // 2D array of tiles that form a level
    Vector2D _stairDown, _stairUp;      // coordinates of stairs up and down
    std::vector<Creature> _creatures;   // array of creatures on this level
    uint _w;                            // width of level
    uint _h;                            // height of level

    /* these attributes are used when generating levels only */
    int _fillprob;              // probability of filling a tile with a wall
    int _r1_cutoff, _r2_cutoff; // cutoff values used in generation algorithm
    int _passes;                // number of algorithm passes made when generating

    /* this method is used by the Generate method to randomly choose a tile type */
    int randpick();

public:
    /* the level constructor may take width and height, as well as values for the generation process */
    Level(uint w = 80, uint h = 24, int fillprob = 40, int r1_cutoff = 5, int r2_cutoff = 0, int passes = 12) :
        _w(w),
        _h(h),
        _fillprob(fillprob),
        _r1_cutoff(r1_cutoff),
        _r2_cutoff(r2_cutoff),
        _passes(passes)
    {
        // allocate memory for map
        _map = new Tile* [_h];
        for(uint i = 0; i < _h; i++) {
            _map[i] = new Tile [_w];
        }

        // generate level
        this->Generate();
    };

    /* level copy constructor */
    Level(const Level& o) {
        // copy old variables
        _w = o._w;
        _h = o._h;
        _stairDown = o._stairDown;
        _stairUp = o._stairUp;
        _fillprob = o._fillprob;
        _r1_cutoff = o._r1_cutoff;
        _r2_cutoff = o._r2_cutoff;
        _passes = o._passes;

        // allocate memory for new map
        _map = new Tile* [_h];
        for(uint i = 0; i < _h; i++) {
            _map[i] = new Tile [_w];
            for(uint j = 0; j < _w; j++) {
                _map[i][j].items = o._map[i][j].items;
                _map[i][j].type = o._map[i][j].type;
                _map[i][j].passable = o._map[i][j].passable;
                _map[i][j].opaque = o._map[i][j].opaque;
            }
            //memcpy(_map[i], o._map[i], _w * sizeof(Tile));
        }
    }

    /* level destructor */
    ~Level() {
        for(uint i = 0; i < _h; i++) {
            delete [] _map[i];
        }
        delete [] _map;
    }

    /* this method generates a new map for this level */
    void Generate();

    /* these functions allow objects easier access to items on a level */
    bool HasItem(Vector2D pos) const;
    item_ptr SeeItem(Vector2D pos) const;
    item_ptr GetItem(Vector2D pos);
    void PutItem(Vector2D pos, item_ptr item);

    /* get methods for attributes */
    Tile** Map() const {return _map;}
    Vector2D StairDown() const {return _stairDown;}
    Vector2D StairUp() const {return _stairUp;}
    uint W() const {return _w;}
    uint H() const {return _h;}
};

#endif
