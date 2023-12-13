#include <stdlib.h>
#include <stdio.h>

#include "statemanager.h"
#include "engine_config.h"

int statemanager_init(struct StateManager *sm) {
    printf("Init StateManager\n");

    sm->states_max = ENGINE_STATEMANAGER_STATES;
    sm->states_current = 0;
    sm->states = calloc(sm->states_max, sizeof(struct State *));

    if (sm->states == NULL) {
        printf("Error: No memory for states\n");
        return 1;
    }

    return 0;
}

int statemanager_close(struct StateManager *sm) {
    printf("StateManager: Closing\n");

    while(sm->states_current > 0) {
        statemanager_pop(sm);
    }

    free(sm->states);

    return 0;
}

int statemanager_change(struct StateManager *sm, struct State *st) {
    statemanager_pop(sm);
    statemanager_push(sm, st);

    return 0;
}

int statemanager_push(struct StateManager *sm, struct State *st) {
    if (st->init != NULL) {
        st->init();
    }

    sm->states[sm->states_current] = st;
    printf("StateManager: New State %d\n", sm->states_current);
    ++sm->states_current;

    return 0;
}

int statemanager_pop(struct StateManager *sm) {
    if (!(sm->states_current > 0)) {
        printf("StateManager: No States on Stack!\n");
        return 1;
    }

    int state_index = sm->states_current - 1;

    if (sm->states[state_index]->destroy != NULL) {
        sm->states[state_index]->destroy();
    }

    sm->states[state_index] = NULL;
    --sm->states_current;
    printf("StateManager: Removed State %d\n", sm->states_current);

    return 0;
}


int statemanager_event(struct StateManager *sm, SDL_Event *event) {
    if (sm->states_current == 0) {
        return 1;
    }

    int state_index = sm->states_current - 1;

    if (sm->states[state_index]->event != NULL) {
        sm->states[state_index]->event(event);
    }

    return 0;
}

int statemanager_update(struct StateManager *sm) {
    if (sm->states_current == 0) {
        return 1;
    }

    int state_index = sm->states_current - 1;

    if (sm->states[state_index]->update != NULL) {
        sm->states[state_index]->update();
    }

    return 0;
}

int statemanager_render(struct StateManager *sm) {
    if (sm->states_current == 0) {
        return 1;
    }

    int state_index = sm->states_current - 1;

    if (sm->states[state_index]->render != NULL) {
        sm->states[state_index]->render();
    }

    return 0;
}

struct State *create_state(
    struct State *state,
    int (*init)(void),
    int (*destory)(void),
    int (*event)(SDL_Event *event),
    int (*update)(void),
    int (*render)(void)
    ) {
    state->init = init;
    state->destroy = destory;
    state->event = event;
    state->update = update;
    state->render = render;

    return state;
}
