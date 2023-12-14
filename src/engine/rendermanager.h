#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

struct RenderManager {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

extern int rendermanager_init(void);
extern int rendermanager_close(void);

#endif
