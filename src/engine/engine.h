#ifndef ENGINE_H
#define ENGINE_H

#include "engine_config.h"
#include "statemanager.h"
#include "rendermanager.h"

struct Engine {
    struct StateManager statemanager;
    struct RenderManager rendermanager;
    // Input Manager
    // Memory Manager
    // Event Manager
    // Asset Manager
    // Audio Manager
    
    int active;
};

extern struct Engine engine;

extern int engine_init(void);
extern int engine_run(void);
extern int engine_close(void);

#endif
