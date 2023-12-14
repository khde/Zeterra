#include <stdio.h>

#include "rendermanager.h"
#include "engine.h"

int rendermanager_init(void) {
    printf("Init RenderManager\n");

    engine.rendermanager.window = SDL_CreateWindow(
            "Zeterra",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800,
            600,
            SDL_WINDOW_SHOWN
            );

    engine.rendermanager.renderer = SDL_CreateRenderer(
            engine.rendermanager.window,
            -1,
            SDL_RENDERER_ACCELERATED
            );

    if(engine.rendermanager.window == NULL) {
        printf("SDL: Error: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

int rendermanager_close(void) {
    printf("RenderManager: Closing\n");
    SDL_DestroyRenderer(engine.rendermanager.renderer);
    SDL_DestroyWindow(engine.rendermanager.window);

    return 0;
}
