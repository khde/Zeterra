#include <stdio.h>

#include "rendermanager.h"

int rendermanager_init(struct RenderManager *rendermanager) {
    printf("Init RenderManager\n");

    rendermanager->window = SDL_CreateWindow(
            "Zeterra",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800,
            600,
            SDL_WINDOW_SHOWN
            );

    rendermanager->renderer = SDL_CreateRenderer(
            rendermanager->window,
            -1,
            SDL_RENDERER_ACCELERATED
            );

    if(rendermanager->window == NULL) {
        printf("SDL: Error: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

int rendermanager_close(struct RenderManager *rendermanager) {
    printf("RenderManager: Closing\n");
    SDL_DestroyRenderer(rendermanager->renderer);
    SDL_DestroyWindow(rendermanager->window);

    return 0;
}
