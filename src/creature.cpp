#include "creature.hpp"
#include "level.hpp"

Creature::Creature(char type) {
    // TODO: Add generation for stats depending on type
    _type = type;
    _hp = _max_hp = 8;
    _mp = _max_mp = 8;
    _xp = 0;
    _pos = {0,0};
    _str = 8;
    _dex = 8;
    _spd = 8;
    _end = 8;
    _int = 8;
    _wis = 8;
    _cha = 8;
}

void Creature::shadowcast(Level& level, uint x, uint y, uint radius, uint row, float start_slope, float end_slope, uint xx, uint xy, uint yx, uint yy) {
    if(start_slope < end_slope) return;
    float next_start_slope = start_slope;

    for(uint i = row; i <= radius; i++) {
        bool blocked = false;

        for(int dx = -i, dy = -i; dx <= 0; dx++) {
            float l_slope = (dx - 0.5) / (dy + 0.5);
            float r_slope = (dx + 0.5) / (dy - 0.5);

            if(start_slope < r_slope) continue;
            else if(end_slope > l_slope) break;

            int sax = dx * xx + dy * xy;
            int say = dx * yx + dy * yy;
            if((sax < 0 && (uint)std::abs(sax) > x) || (say < 0 && (uint)std::abs(say) > y)) continue;

            uint ax = x + sax;
            uint ay = y + say;
            if(ax >= level.W() || ay >= level.H()) continue;

            uint radius2 = radius * radius;
            if((uint)(dx * dx + dy * dy) < radius2) {
                Vector2D tmp = {ax, ay};
                _vis.push_back(tmp);
            }

            if(blocked) {
                if(level.Map()[ay][ax].opaque) {
                    next_start_slope = r_slope;
                    continue;
                }
                else {
                    blocked = false;
                    start_slope = next_start_slope;
                }
            }
            else if(level.Map()[ay][ax].opaque) {
                blocked = true;
                next_start_slope = r_slope;
                shadowcast(level, x, y, radius, i+1, start_slope, l_slope, xx, xy, yx, yy);
            }
        }

        if(blocked) break;
    }
}
const int octantMatrix[4][8] = {
    { 1, 0, 0,-1,-1, 0, 0, 1},
    { 0, 1,-1, 0, 0,-1, 1, 0},
    { 0, 1, 1, 0, 0,-1,-1, 0},
    { 1, 0, 0, 1,-1, 0, 0,-1}
};

void Creature::FOV(Level& level) {
    _vis.clear();
    for(uint i = 0; i < 8; i++) shadowcast(level, _pos.x, _pos.y, 10, 1, 1.0, 0.0, octantMatrix[0][i], octantMatrix[1][i], octantMatrix[2][i], octantMatrix[3][i]);
}
