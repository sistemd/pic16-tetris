// CONFIG1
#pragma config "FOSC = INTRC_NOCLKOUT" // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config "WDTE = OFF"            // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config "PWRTE = OFF"           // Power-up Timer Enable bit (PWRT disabled)
#pragma config "MCLRE = ON"            // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config "CP = OFF"              // Code Protection bit (Program memory code protection is disabled)
#pragma config "CPD = OFF"             // Data Code Protection bit (Data memory code protection is disabled)
#pragma config "BOREN = OFF"           // Brown Out Reset Selection bits (BOR disabled)
#pragma config "IESO = OFF"            // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config "FCMEN = OFF"           // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config "LVP = OFF"             // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config "BOR4V = BOR40V"   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config "WRT = OFF"        // Flash Program Memory Self Write Enable bits (Write protection off)

#define _XTAL_FREQ 8000000

#include "Tetris.h"
#include "Buttons.h"
#include "Drawing.h"
#include "LCD.h"
#include <xc.h>
#include <stdint.h>

enum
{
    TIMER_SKIP_LIMIT = UINT16_MAX,
};

typedef enum {
    FAST_TIMER_PRESCALER = 1,
    DEFAULT_TIMER_PRESCALER = 16,
} TimerPrescaler;

static uint8_t timerPrescaler = DEFAULT_TIMER_PRESCALER;

static uint8_t updateReady = 0;

static void SetupOscillator(void)
{
    /* Make sure _XTAL_FREQ matches this configuration. */

    IRCF0 = 1;
    IRCF1 = 1;
    IRCF2 = 1;
}

static void SetupTimer(void)
{
    TMR1IE = 1;
    TMR1CS = 0;
    PEIE = 1;
    TMR1ON = 1;
    T1CKPS0 = 1;
    T1CKPS1 = 0;
}

static void ResetTimer(void)
{
    TMR1 = 0;
}

static void __interrupt() InterruptHandler(void)
{
    static uint8_t timerInterruptCounter = 0;

    if (INTE && INTF)
    {
        INTF = 0;
        /* Should toggle sleep here (how?). Only put into sleep if wakeup didn't just happen. Do I need to disable the WDT? */
    }

    if (TMR1IE && TMR1IF)
    {
        TMR1IF = 0;
        ++timerInterruptCounter;
        if (timerInterruptCounter >= timerPrescaler)
        {
            updateReady = 1;
            timerInterruptCounter = 0;
        }
    }
}

void main(void)
{
    /* Don't forget to turn on the WDT later. */

    SetupOscillator();

    Buttons_SetupPortsAndInterrups();

    LCD_SetupPorts();
    LCD_Reset();
    LCD_SegmentSelection(LCD_BOTH_SEGMENTS);
    LCD_Clear();
    LCD_TurnOn();

    Buttons buttons;
    Tetris_Game tetrisGame;

    SetupTimer();

    while (1)
    {
        Tetris_ResetGame(&tetrisGame, Tetris_GetRandomUnit());
        Buttons_Clear(&buttons);
        ResetTimer();

        while (1)
        {
            Buttons_Update(&buttons);

            if (buttons.left.pressed)
                Tetris_MovePlayerLeft(&tetrisGame);
            if (buttons.right.pressed)
                Tetris_MovePlayerRight(&tetrisGame);
            if (buttons.rotate.pressed)
                Tetris_RotatePlayer(&tetrisGame);

            if (buttons.down.held)
                timerPrescaler = FAST_TIMER_PRESCALER;
            else
                timerPrescaler = DEFAULT_TIMER_PRESCALER;

            if (updateReady)
            {
                updateReady = 0;
                if (Tetris_UpdateGame(&tetrisGame) == TETRIS_GAME_OVER)
                    break;
            }

            RedrawTetrisOnLCD(&tetrisGame);
        }
    }
}

/* mogwai fear satan */
