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

extern inline void rendermanager_present(void);
inline int rendermanager_clear(void);
extern inline int rendermanager_set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
extern inline int rendermanager_draw_rect(SDL_Rect *rect);
extern inline int rendermanager_fill_rect(SDL_Rect *rect);

#endif
