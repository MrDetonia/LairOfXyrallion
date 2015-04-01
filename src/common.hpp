#ifndef _LoX_COMMON
#define _LoX_COMMON

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <random>
#include <vector>
#include <list>

typedef unsigned char uchar;
typedef unsigned int uint;

struct Vector2D {
    uint x;
    uint y;

    bool operator==(const Vector2D& vect) {
        if(x == vect.x && y == vect.y) return true;
        return false;
    }
};

#endif
