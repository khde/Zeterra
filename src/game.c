#include <stdio.h>
#include <SDL2/SDL.h>

#include "engine/engine.h"
#include "game.h"
#include "world.h"
#include "player.h"

struct State game;
struct Game g;

int game_init(void) {
    printf("Game Loading...\n");
    g.player.pos.x = 200;
    g.player.pos.y = 300;
    g.player.r.h = 80;
    g.player.r.w = 20;
    g.player.r.x = g.player.pos.x;  // Bruh
    g.player.r.y = g.player.pos.y;

    g.world = *world_create();

    camera_init(&g.camera);
    camera_set_follow(&g.camera, &g.player.pos);

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
                g.player.pos.y += 50;
                break;
            case SDLK_a:
                g.player.pos.x += 50;
                break;
            case SDLK_s:
                g.player.pos.y -= 50;
                break;
            case SDLK_d:
                g.player.pos.x -= 50;
                break;
            default:
                // Okay
                break; 
        }
    }
    return 0;
}

int game_update(void){
    camera_update(&g.camera);
    return 0;
}

int game_render(void){
    rendermanager_set_color(135, 206, 235, 255);
    rendermanager_clear();

    rendermanager_set_color(35, 06, 35, 255);
    // Temporary
    g.player.r.x = g.player.pos.x - g.camera.pos.x + 400;
    g.player.r.y = g.player.pos.y - g.camera.pos.y + 300;
    rendermanager_fill_rect(&g.player.r);

    world_render(&g.world, &g.camera);

    rendermanager_present();

    return 0;
}
