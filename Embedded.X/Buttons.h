#pragma once

#include <xc.h>

typedef struct {
    unsigned pressed : 1;
    unsigned held : 1;
} Button;

typedef struct {
    Button left;
    Button right;
    Button down;
    Button rotate;
} Buttons;

extern void Buttons_Setup(void);

extern void Buttons_Clear(Buttons *buttons);

extern void Buttons_Update(Buttons *buttons);
