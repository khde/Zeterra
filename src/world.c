#include <stdlib.h>
#include <SDL2/SDL.h>

#include "engine/engine.h"
#include "world.h"

struct World *world_create() {
    struct World *world = malloc(sizeof(struct World));
    
    for (int y = 0; y < CHUNKDIMENSION; y++) {
        for (int x = 0; x < CHUNKDIMENSION; x++) {
            world->chunks.tiles[y][x].x = TILEDIMENSION * x;
            world->chunks.tiles[y][x].y = TILEDIMENSION * y;
        }
    }
    return world;
}

void world_render_world(struct World *world) {
    SDL_SetRenderDrawColor(engine.rendermanager.renderer, 124, 252, 0, 255);
    world_render_chunk(&world->chunks);

    // SDL_RenderFillRect(engine.rendermanager.renderer, Rectangle);
}

void world_render_chunk(struct Chunk *chunk) {
    SDL_Rect rect;
    rect.h = TILEDIMENSION;
    rect.w = TILEDIMENSION;

    for (int y = 0; y < CHUNKDIMENSION; y++) {
            for (int x = 0; x < CHUNKDIMENSION; x++) {
                rect.x = chunk->tiles[y][x].x;
                rect.y = chunk->tiles[y][x].y;
                SDL_RenderDrawRect(engine.rendermanager.renderer, &rect);
                rect.x = x * TILEDIMENSION;
            }
            rect.x = 0;
        }
}
