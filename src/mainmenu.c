#include "SDL2/SDL.h"

#include "engine/engine.h"
#include "mainmenu.h"
#include "game.h"

int mainmenu_init(void) {

    return 0;
}

int mainmenu_destroy(void) {

    return 0;
}

int mainmenu_event(SDL_Event *event) {
    if (event->key.keysym.sym == SDLK_SPACE) {
        create_state(
            &game,
            game_init,
            game_destroy,
            game_event,
            game_update,
            game_render
            );
        statemanager_push(&engine.statemanager, &game);
    }
    return 0;
}

int mainmenu_update(void) {

    return 0;
}

int mainmenu_render(void) {
    SDL_SetRenderDrawColor(engine.rendermanager.renderer, 50, 50, 50, 255);
    SDL_RenderClear(engine.rendermanager.renderer);
    SDL_RenderPresent(engine.rendermanager.renderer);

    return 0;
}
