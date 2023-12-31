#include <stdlib.h>
#include <SDL2/SDL.h>

#include "engine/engine.h"
#include "world.h"
#include "math.h"

static void world_create_chunk(struct Chunk *chunk, unsigned int cy, unsigned int cx);
static void world_render_chunk(struct Chunk *chunk, struct Camera *camera);

struct World *world_create() {
    struct World *world = malloc(sizeof(struct World));

    for (unsigned int y = 0; y < WORLDHEIGHT; y++) {
        for (unsigned int x = 0; x < WORLDWIDTH; x++) {
            world_create_chunk(&world->chunks[y][x], y, x);
        }
    }
    return world;
}

static void world_create_chunk(struct Chunk *chunk, unsigned int cy, unsigned int cx) {
    chunk->x = cx;
    chunk->y = cy;
    for (unsigned int y = 0; y < CHUNKHEIGHT; y++) {
        for (unsigned int x = 0; x < CHUNKWIDTH; x++) {
            chunk->tiles[y][x].pos.x = x + (cx * CHUNKWIDTH);
            chunk->tiles[y][x].pos.y = y + (cy * CHUNKHEIGHT);
#ifdef DEBUG
            printf("%d:%d ", chunk->tiles[y][x].pos.x, chunk->tiles[y][x].pos.y);
#endif
        }
#ifdef DEBUG
        puts("\n");
#endif
    }
#ifdef DEBUG
    puts("\n");
#endif
}

void world_render(struct World *world, struct Camera *camera) {
    rendermanager_set_color(29, 39, 57, 255);
    for (int y = 0; y < WORLDHEIGHT; y++) {
        for (int x = 0; x < WORLDWIDTH; x++) {
            world_render_chunk(&world->chunks[y][x], camera);
        }
    }
}

static void world_render_chunk(struct Chunk *chunk, struct Camera *camera) {
    SDL_Rect rect;
    rect.h = TILEHEIGHT;
    rect.w = TILEWIDTH;
    rendermanager_set_color(0, 39, 57, 255);

    for (int y = 0; y < CHUNKHEIGHT; y++) {
        for (int x = 0; x < CHUNKWIDTH; x++) {
            rect.x = (chunk->tiles[y][x].pos.x * TILEWIDTH) + camera->pos.x;
            rect.y = (chunk->tiles[y][x].pos.y * TILEHEIGHT) + camera->pos.y;
            rendermanager_draw_rect(&rect);
        }
    }
}
