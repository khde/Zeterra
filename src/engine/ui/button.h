#ifndef BUTTON_H
#define BUTTON_H

struct Button {
    int x;
    int y;
    int width;
    int height;
    void (*event)(void);
};

#endif
