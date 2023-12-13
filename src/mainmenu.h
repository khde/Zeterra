#ifndef MAINMENU_H
#define MAINMENU_H

#include <SDL2/SDL.h>

extern int mainmenu_init(void);
extern int mainmenu_destroy(void);

extern int mainmenu_event(SDL_Event *event);
extern int mainmenu_update(void);
extern int mainmenu_render(void);

#endif
