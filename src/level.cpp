#include "level.hpp"
#include "character.hpp"

int Level::randpick() {
    if(rand()%100 < _fillprob) return MAP_WALL;
    return MAP_FLOOR;
}

void floodmap(Tile** &map, Tile** &flag, uint x, uint y) {
    // do nothing if this cell is a wall
    if(map[y][x].type == MAP_WALL) return;

    // do nothing if we have already flagged this cell
    if(flag[y][x].type == MAP_FLOOR) return;

    // flag this cell as floor
    flag[y][x] = tiles[MAP_FLOOR];

    // call recursively in all directions
    floodmap(map, flag, x-1, y);
    floodmap(map, flag, x+1, y);
    floodmap(map, flag, x, y-1);
    floodmap(map, flag, x, y+1);
}

void Level::Generate() {

    // allocate memory for levels
    Tile** new_map = new Tile* [_h];
    Tile** flooded_map = new Tile* [_h];
    for(uint i = 0; i < _h; i++) {
        new_map[i] = new Tile [_w];
        flooded_map[i] = new Tile [_w];
    }

    while(1) {
        // randomly fill starting level
        for(uint y = 1; y < _h -1; y++) {
            for(uint x = 1; x < _w; x++) {
                _map[y][x] = tiles[randpick()];
            }
        }

        // fill temp level with walls
        for(uint y = 0; y < _h; y++) {
            for(uint x = 0; x < _w; x++) {
                new_map[y][x] = tiles[MAP_WALL];
            }
        }

        // ensure the level has outer walls
        for(uint y = 0; y < _h; y++) {
            _map[y][0] = _map[y][_w-1] = tiles[MAP_WALL];
        }
        for(uint x = 0; x < _w; x++) {
            _map[0][x] = _map[_h-1][x] = tiles[MAP_WALL];
        }

        // run cellular autonoma algorithm
        for(uint y = 1; y < _h - 1; y++) {
            for(uint x = 1; x < _w - 1; x++) {
                int adjcount_r1 = 0,
                    adjcount_r2 = 0;

                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        if(_map[y+i][x+j].type != MAP_FLOOR) adjcount_r1++;
                    }
                }

                for(uint i = y - 2; i <= y + 2; i++) {
                    for(uint j = x - 2; j <= x + 2; j++) {
                        if(abs(i-y) == 2 && abs(j-x) == 2) continue;
                        if(i >= _h || j >= _w) continue;
                        if(_map[i][j].type != MAP_FLOOR) adjcount_r2++;
                    }
                }

                // select new tile for this position
                if(adjcount_r1 >= _r1_cutoff || adjcount_r2 <= _r2_cutoff) {
                    new_map[y][x] = tiles[MAP_WALL];
                }
                else {
                    new_map[y][x] = tiles[MAP_FLOOR];
                }
            }
        }

        // flood map from random floor cell
        int rnd_x, rnd_y;
        while(1) {
            rnd_x = rand() % _w;
            rnd_y = rand() % _h;

            if(new_map[rnd_y][rnd_x].type == MAP_FLOOR) break;
        }

        for(uint y = 0; y < _h; y++) {
            for(uint x = 0; x < _w; x++) {
                flooded_map[y][x] = tiles[MAP_WALL];
            }
        }

        floodmap(new_map, flooded_map, rnd_x, rnd_y);

        // ensure that at least 1/2 of the map is floor
        uint floorcount = 0;
        for(uint y = 0; y < _h; y++) {
            for(uint x = 0; x < _w; x++) {
                if(flooded_map[y][x].type == MAP_FLOOR) floorcount++;
            }
        }

        if(floorcount > (_w*_h)/2) break;
    }

    // place stairs
    int rnd_x, rnd_y;
    while(1) {
        rnd_x = rand() % _w;
        rnd_y = rand() % _h;

        if(flooded_map[rnd_y][rnd_x].type == MAP_FLOOR) {
            flooded_map[rnd_y][rnd_x] = tiles[MAP_STAIR_DOWN];
            _stairDown.x = rnd_x;
            _stairDown.y = rnd_y;
            break;
        }
    }
    while(1) {
        rnd_x = rand() % _w;
        rnd_y = rand() % _h;

        if(flooded_map[rnd_y][rnd_x].type == MAP_FLOOR) {
            flooded_map[rnd_y][rnd_x] = tiles[MAP_STAIR_UP];
            _stairUp.x = rnd_x;
            _stairUp.y = rnd_y;
            break;
        }
    }

    // replace map with new one
    for(uint y = 1; y < _h - 1; y++) {
        for(uint x = 1; x < _w -1; x++) {
            _map[y][x] = flooded_map[y][x];
        }
    }

    // free memory used up by temporary maps
    for(uint i = 0; i < _h; i++) {
        delete [] new_map[i];
        delete [] flooded_map[i];
    }
    delete [] new_map;
    delete [] flooded_map;

    // scatter items around level
    for(uint i = 0; i < 30; i++) {
        Die tmp = {1, _h-1, 0};
        uint y = DieRoll::Roll(tmp);
        tmp.Set(1, _w-1, 0);
        uint x = DieRoll::Roll(tmp);

        if(_map[y][x].type == MAP_FLOOR) _map[y][x].items.push_back(Item::Generate());
    }
}

bool Level::HasItem(Vector2D pos) const {
    return !_map[pos.y][pos.x].items.empty();
}

item_ptr Level::SeeItem(Vector2D pos) const {
    return _map[pos.y][pos.x].items.back();
}

item_ptr Level::GetItem(Vector2D pos) {
    item_ptr tmp = _map[pos.y][pos.x].items.back();
    _map[pos.y][pos.x].items.pop_back();
    return tmp;
}

void Level::PutItem(Vector2D pos, item_ptr item) {
    _map[pos.y][pos.x].items.push_back(item);
}
