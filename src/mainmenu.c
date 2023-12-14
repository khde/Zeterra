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
        statemanager_create_state(
            &game,
            game_init,
            game_destroy,
            game_event,
            game_update,
            game_render
            );
        statemanager_push(&game);
    }
    return 0;
}

int mainmenu_update(void) {

    return 0;
}

int mainmenu_render(void) {
    rendermanager_set_color(50, 50, 50, 255);
    rendermanager_clear();
    rendermanager_present();

    return 0;
}
