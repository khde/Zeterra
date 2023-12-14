#ifndef WORLD_H
#define WORLD_H

#define TILEHEIGHT 32
#define TILEWIDTH 32

#define CHUNKHEIGHT 16
#define CHUNKWIDTH 16

#define WORLDHEIGHT 32
#define WORLDWIDTH 32

struct Tile {
    unsigned int x;
    unsigned int y;
};

struct Chunk {
    struct Tile tiles[CHUNKHEIGHT][CHUNKWIDTH];
    unsigned int x;
    unsigned int y;
};

struct World {
    struct Chunk chunks[WORLDHEIGHT][WORLDWIDTH];
};

extern struct World *world_create();
extern void world_render(struct World *world);

#endif
