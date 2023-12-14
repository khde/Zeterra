#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "engine/engine.h"
#include "world.h"

extern struct State game;

struct Game {
    struct World world;
};

extern int game_init(void);
extern int game_destroy(void);

extern int game_event(SDL_Event *event);
extern int game_update(void);
extern int game_render(void);

#endif
