#ifndef CONFIG_H
#define CONFIG_H

#define DEBUG
#ifdef DEBUG
    #define DEBUG_STR "Debug"
#else
    #define DEBUG_STR
#endif

#define ENGINE_NAME "Zeterra"
#define ENGINE_VERSION 0.01
#define ENGINE_VERSION_STR "v0.01"
#define ENGINE_TITLE ENGINE_NAME " " ENGINE_VERSION_STR " " DEBUG_STR "\n"

#define ENGINE_STATEMANAGER_STATES 10

struct EngineConfig {
    ;
};

#endif
