#ifndef _LoX_COMMON
#define _LoX_COMMON

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <random>

struct Vector2D {
    int x;
    int y;
    
    bool operator==(const Vector2D& vect) {
        if(x == vect.x && y == vect.y) return true;
        return false;
    }
};

#endif
