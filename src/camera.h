#ifndef CAMERA_H
#define CAMERA_H

#include "math.h"

struct Camera {
    struct Point *follow;
    struct Point pos;
    // Make so it only moves when on edges of screen, some int values idk
};

extern void camera_init(struct Camera *camera);
extern int camera_set_follow(struct Camera *camera, struct Point *pos);
extern void camera_update(struct Camera *camera);

#endif
