#include "engine/engine.h"
#include "mainmenu.h"

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    struct State mainmenu;
    statemanager_create_state(
        &mainmenu,
        mainmenu_init,
        mainmenu_destroy,
        mainmenu_event,
        mainmenu_update,
        mainmenu_render
    );


    engine_init();
    statemanager_push(&mainmenu);
    engine_run();
    engine_close();

    return 0;
}
