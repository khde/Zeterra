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

    g.camera.x = 0;
    g.camera.y = 0;

    return 0;
}

int game_destroy(void){

    return 0;
}

int game_event(SDL_Event *event){
    if (event->type == SDL_KEYDOWN) {
        switch(event->key.keysym.sym) {
            case SDLK_ESCAPE:
                statemanager_pop();
                break;
            case SDLK_w:
                g.camera.y += 50;
                break;
            case SDLK_a:
                g.camera.x += 50;
                break;
            case SDLK_s:
                g.camera.y -= 50;
                break;
            case SDLK_d:
                g.camera.x -= 50;
                break;
            default:
                // Okay
                break; 
        }
    }

    return 0;
}

int game_update(void){

    return 0;
}

int game_render(void){
    rendermanager_set_color(135, 206, 235, 255);
    rendermanager_clear();

    rendermanager_set_color(35, 06, 35, 255);
    rendermanager_fill_rect(&player.r);

    world_render(&g.world, &g.camera);

    rendermanager_present();

    return 0;
}
