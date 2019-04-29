#include "Buttons.h"
#include <stdint.h>
#include <string.h>

#define nPAUSE_BUTTON  RB0
#define nROTATE_BUTTON RB1
#define nLEFT_BUTTON   RB2
#define nRIGHT_BUTTON  RB3
#define nDOWN_BUTTON   RB4

static void Buttons_SetupPortB(void)
{
    TRISB = 0xFF;
    ANSELH = 0;
    WPUB = 0b00011111;
    nRBPU = 0;
}

static void Buttons_SetupInterrupts(void)
{
    GIE = 1;
    INTE = 1;
    INTEDG = 0;
}

static void Buttons_UpdateButton(Button *button, uint8_t nHeld)
{
    if (!nHeld)
    {
        button->pressed = !button->held;
        button->held = 1;
    }
    else
    {
        button->pressed = 0;
        button->held = 0;
    }
}

void Buttons_SetupPortsAndInterrups(void)
{
    Buttons_SetupPortB();
    Buttons_SetupInterrupts();
}

void Buttons_Clear(Buttons *buttons)
{
    memset(buttons, 0, sizeof *buttons);
}

void Buttons_Update(Buttons *buttons)
{
    Buttons_UpdateButton(&buttons->left, nLEFT_BUTTON);
    Buttons_UpdateButton(&buttons->right, nRIGHT_BUTTON);
    Buttons_UpdateButton(&buttons->down, nDOWN_BUTTON);
    Buttons_UpdateButton(&buttons->rotate, nROTATE_BUTTON);
}
