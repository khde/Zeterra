#ifndef RENDER_H
#define RENDER_H

#include <stdint.h>
#include <SDL2/SDL.h>

struct RenderManager {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

extern int rendermanager_init(void);
extern int rendermanager_close(void);

extern void rendermanager_present(void);
extern int rendermanager_clear(void);
extern int rendermanager_set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
extern int rendermanager_draw_rect(SDL_Rect *rect);
extern int rendermanager_fill_rect(SDL_Rect *rect);

#endif
