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

#include "Tetris.h"
#include "Buttons.h"
#include "Drawing.h"
#include "Frequency.h"
#include "LCD.h"
#include <xc.h>
#include <stdint.h>
#include <stdlib.h>

#include "Compatibility.h"

__eeprom uint16_t highscore = 0;

__eeprom uint16_t uniqueSeed = 0;

enum
{
    TIMER_SKIP_LIMIT = UINT16_MAX,
};

typedef enum {
    FAST_TIMER_PRESCALER = 1,
    EASY_TIMER_PRESCALER = 12,
    MEDIUM_TIMER_PRESCALER = 9,
    HARD_TIMER_PRESCALER = 6,
    ULTIMATE_TIMER_PRESCALER = 3,
} TimerPrescaler;

typedef enum {
    EASY_SCORE_LIMIT = 3,
    MEDIUM_SCORE_LIMIT = 7,
    HARD_SCORE_LIMIT = 10,
    ULTIMATE_SCORE_LIMIT = 20,
} ScoreLimit;

static uint8_t timerPrescaler = EASY_TIMER_PRESCALER;

static uint8_t defaultTimerPrescaler = EASY_TIMER_PRESCALER;

static uint8_t updateReady = 0;

/*
  This should be set to 0 initially. However, for some reason I break into the interrupt handler
  due to some external interrupt during startup. I don't know why that happens. I should fix this.
*/
static uint8_t paused = 1;

static void SetupTimer(void)
{
    GIE = 1;
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
        __delay_us(25); /* A poor man's attempt to debounce his switch */
        INTF = 0;

        if (!paused)
        {
            paused = 1;
            SLEEP();
        }
        else
        {
            paused = 0;
        }
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

static void SetupRandomness(void)
{
    srand(uniqueSeed);
    ++uniqueSeed;
}

static void Setup(void)
{
    SetupOscillator();
    SetupRandomness();
    SetupTimer();

    LCD_SetupPorts();
    LCD_Reset();
    LCD_SegmentSelection(LCD_BOTH_SEGMENTS);
    LCD_Clear();
    LCD_TurnOn();

    Buttons_Setup();
    GIE = 1;
}

static void UpdateDifficulty(Tetris_Game *tetrisGame)
{
    switch (defaultTimerPrescaler)
    {
    case EASY_TIMER_PRESCALER:
        if (tetrisGame->currentScore > EASY_SCORE_LIMIT)
            defaultTimerPrescaler = MEDIUM_TIMER_PRESCALER;
        break;
    case MEDIUM_TIMER_PRESCALER:
        if (tetrisGame->currentScore > MEDIUM_SCORE_LIMIT)
            defaultTimerPrescaler = HARD_TIMER_PRESCALER;
        break;
    case HARD_TIMER_PRESCALER:
        if (tetrisGame->currentScore > HARD_SCORE_LIMIT)
            defaultTimerPrescaler = ULTIMATE_TIMER_PRESCALER;
        break;
    }
}

void main(void)
{
    /* Don't forget to turn on the WDT later. */
    Setup();

    Tetris_Game tetrisGame;
    Buttons buttons;

    while (1)
    {
        Tetris_ResetGame(&tetrisGame, Tetris_GetRandomUnit());
        defaultTimerPrescaler = EASY_TIMER_PRESCALER;
        Buttons_Clear(&buttons);
        ResetTimer();

        DrawCurrentScore(&tetrisGame);
        DrawHighscore(highscore);

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
                timerPrescaler = defaultTimerPrescaler;
            
            if (updateReady)
            {
                updateReady = 0;
                uint8_t status = Tetris_UpdateGame(&tetrisGame);
                if (status == TETRIS_PLAYER_SCORED)
                {
                    DrawCurrentScore(&tetrisGame);
                    UpdateDifficulty(&tetrisGame);
                }
                else if (status == TETRIS_GAME_OVER)
                {
                    break;
                }
            }

            DrawTetris(&tetrisGame);
        }

        if (tetrisGame.currentScore > highscore)
        {
            highscore = tetrisGame.currentScore;
            FlashVictoriously();
        }
    }
}

/* mogwai fear satan */
