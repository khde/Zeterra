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

    statemanager_init(&engine.statemanager);
    rendermanager_init(&engine.rendermanager);

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
            statemanager_event(&engine.statemanager, &event);
        }

        statemanager_update(&engine.statemanager);
        statemanager_render(&engine.statemanager);
    }

    return 0;
}

int engine_close(void) {
    rendermanager_close(&engine.rendermanager);
    statemanager_close(&engine.statemanager);
    SDL_Quit();

    return 0;
}
