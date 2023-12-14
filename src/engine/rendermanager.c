#include <stdio.h>
#include <SDL2/SDL.h>

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


inline void rendermanager_present(void) {
    SDL_RenderPresent(engine.rendermanager.renderer);
}

inline int rendermanager_clear(void) {
    return SDL_RenderClear(engine.rendermanager.renderer);
}

inline int rendermanager_set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return SDL_SetRenderDrawColor(engine.rendermanager.renderer, r, g, b, a);
}

inline int rendermanager_draw_rect(SDL_Rect *rect) {
    return SDL_RenderDrawRect(engine.rendermanager.renderer, rect);
}

inline int rendermanager_fill_rect(SDL_Rect *rect) {
    return SDL_RenderFillRect(engine.rendermanager.renderer, rect);
}
