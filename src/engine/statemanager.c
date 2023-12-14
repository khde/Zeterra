#include <stdlib.h>
#include <stdio.h>

#include "statemanager.h"
#include "engine.h"
#include "engine_config.h"

int statemanager_init(void) {
    printf("Init StateManager\n");

    engine.statemanager.states_max = ENGINE_STATEMANAGER_STATES;
    engine.statemanager.states_current = 0;
    engine.statemanager.states = calloc(engine.statemanager.states_max, sizeof(struct State *));

    if (engine.statemanager.states == NULL) {
        printf("Error: No memory for states\n");
        return 1;
    }

    return 0;
}

int statemanager_close(void) {
    printf("StateManager: Closing\n");

    while(engine.statemanager.states_current > 0) {
        statemanager_pop();
    }

    free(engine.statemanager.states);

    return 0;
}

int statemanager_change(struct State *st) {
    statemanager_pop();
    statemanager_push(st);

    return 0;
}

int statemanager_push(struct State *st) {
    if (st->init != NULL) {
        st->init();
    }

    engine.statemanager.states[engine.statemanager.states_current] = st;
    printf("StateManager: New State %d\n", engine.statemanager.states_current);
    ++engine.statemanager.states_current;

    return 0;
}

int statemanager_pop(void) {
    if (!(engine.statemanager.states_current > 0)) {
        printf("StateManager: No States on Stack!\n");
        return 1;
    }

    int state_index = engine.statemanager.states_current - 1;

    if (engine.statemanager.states[state_index]->destroy != NULL) {
        engine.statemanager.states[state_index]->destroy();
    }

    engine.statemanager.states[state_index] = NULL;
    --engine.statemanager.states_current;
    printf("StateManager: Removed State %d\n", engine.statemanager.states_current);

    return 0;
}


int statemanager_event(SDL_Event *event) {
    if (engine.statemanager.states_current == 0) {
        return 1;
    }

    int state_index = engine.statemanager.states_current - 1;

    if (engine.statemanager.states[state_index]->event != NULL) {
        engine.statemanager.states[state_index]->event(event);
    }

    return 0;
}

int statemanager_update(void) {
    if (engine.statemanager.states_current == 0) {
        return 1;
    }

    int state_index = engine.statemanager.states_current - 1;

    if (engine.statemanager.states[state_index]->update != NULL) {
        engine.statemanager.states[state_index]->update();
    }

    return 0;
}

int statemanager_render(void) {
    if (engine.statemanager.states_current == 0) {
        return 1;
    }

    int state_index = engine.statemanager.states_current - 1;

    if (engine.statemanager.states[state_index]->render != NULL) {
        engine.statemanager.states[state_index]->render();
    }

    return 0;
}

struct State *statemanager_create_state(
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
