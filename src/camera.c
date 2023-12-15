#include <stddef.h>
#include "camera.h"

void camera_init(struct Camera *camera) {
    camera->pos.x = 0;
    camera->pos.y = 0;
}

int camera_set_follow(struct Camera *camera, struct Point *pos) {
    if (pos != NULL) {
        camera->follow = pos;
        return 0;
    }
    return 1;
}


void camera_update(struct Camera *camera) {
    camera->pos.x = camera->follow->x;
    camera->pos.y = camera->follow->y;
}
