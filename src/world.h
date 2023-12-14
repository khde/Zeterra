#ifndef WORLD_H
#define WORLD_H

#define TILEDIMENSION 32
#define CHUNKDIMENSION 32

struct Tile {
    unsigned int x;
    unsigned int y;
};

struct Chunk {
    struct Tile tiles[CHUNKDIMENSION][CHUNKDIMENSION];
    unsigned int x;
    unsigned int y;
};

struct World {
    struct Chunk chunks;
};

extern struct World *world_create();
extern void world_render_world(struct World *world);
extern void world_render_chunk(struct Chunk *chunk);

#endif
