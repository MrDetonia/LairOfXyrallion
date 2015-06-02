#ifndef _LoX_COMMON
#define _LoX_COMMON

/* version string */
#define _LoX_VERSION 0.1.0.2

/* global external headers */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <memory>
#include <string>
#include <random>
#include <vector>
#include <list>

/* global internal headers */
#include "dieroll.hpp"

/* easier declaration of unsigned integers */
typedef unsigned char uchar;
typedef unsigned int uint;

/* this structure is used to describe 2D positions and movements in the game */
struct Vector2D {
    uint x;
    uint y;

    /* overload for '==' operator to work correctly */
    bool operator==(const Vector2D& vect) {
        if(x == vect.x && y == vect.y) return true;
        return false;
    }
};

#endif
