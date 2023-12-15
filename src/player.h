#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "math.h"

struct Player {
    struct Point pos;
    SDL_Rect r;
};

#endif
