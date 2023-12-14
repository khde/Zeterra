#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <SDL2/SDL.h>

struct State {
    int (*init)(void);
    int (*destroy)(void);

    int (*event)(SDL_Event *event);
    int (*update)(void);
    int (*render)(void);
};

struct StateManager {
    struct State **states;
    unsigned int states_max;
    unsigned int states_current;
};

extern int statemanager_init(struct StateManager *sm);
extern int statemanager_close(struct StateManager *sm);

extern int statemanager_change(struct StateManager *sm, struct State *st);
extern int statemanager_push(struct StateManager *sm, struct State *st);
extern int statemanager_pop(struct StateManager *sm);

extern int statemanager_event(struct StateManager *sm, SDL_Event *event);
extern int statemanager_update(struct StateManager *sm);
extern int statemanager_render(struct StateManager *sm);

extern struct State *statemanager_create_state(
    struct State *state,
    int (*init)(void),
    int (*destory)(void),
    int (*event)(SDL_Event *event),
    int (*update)(void),
    int (*render)(void)
    );

#endif
