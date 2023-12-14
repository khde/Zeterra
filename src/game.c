#include <stdio.h>
#include <SDL2/SDL.h>

#include "engine/engine.h"
#include "game.h"
#include "world.h"
#include "player.h"

struct State game;
struct Game g;
struct Player player;

int game_init(void) {
    printf("Game Loading...\n");
    player.x = 200;
    player.y = 300;
    player.r.h = 80;
    player.r.w = 20;
    player.r.x = player.x;  // Bruh
    player.r.y = player.y;

    g.world = *world_create();

    return 0;
}

int game_destroy(void){

    return 0;
}

int game_event(SDL_Event *event){
    if (event->key.keysym.sym == SDLK_ESCAPE) {
        statemanager_pop();
    }
    return 0;
}

int game_update(void){

    return 0;
}

int game_render(void){
    SDL_SetRenderDrawColor(engine.rendermanager.renderer, 135, 206, 235, 255);
    SDL_RenderClear(engine.rendermanager.renderer);

    SDL_SetRenderDrawColor(engine.rendermanager.renderer, 35, 06, 35, 255);
    SDL_RenderFillRect(engine.rendermanager.renderer, &player.r);

    world_render(&g.world);

    SDL_RenderPresent(engine.rendermanager.renderer);

    return 0;
}
