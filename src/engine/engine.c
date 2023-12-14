#include <stdio.h>
#include <SDL2/SDL.h>

#include "engine.h"
#include "engine_config.h"
#include "statemanager.h"
#include "rendermanager.h"

struct Engine engine;

int engine_init(void) {
    printf(ENGINE_TITLE);

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL Init Error: %s\n", SDL_GetError());
        return 1;
    }

    statemanager_init();
    rendermanager_init();

    engine.active = 1;

    return 0;
}

int engine_run(void) {
    SDL_Event event;
    while(engine.active) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                engine.active = 0;
            }
            statemanager_event(&event);
        }
        statemanager_update();
        statemanager_render();
    }

    return 0;
}

int engine_close(void) {
    rendermanager_close();
    statemanager_close();
    SDL_Quit();

    return 0;
}
