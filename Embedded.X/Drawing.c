#include "Drawing.h"
#include "LCD.h"
#include "Font.h"
#include "Digits.h"
#include "Frequency.h"
#include <xc.h>

#include "Compatibility.h"

typedef enum {
    GAME_PIXEL_WIDTH = LCD_WIDTH / TETRIS_TABLE_WIDTH,
    GAME_PIXEL_HEIGHT = (LCD_HEIGHT - FONT_HEIGHT) / TETRIS_TABLE_HEIGHT,
} GamePixelSize;

static void DrawTetrisGameColumn(Tetris_Game *tetrisGame, uint8_t x, uint16_t rightMask, uint16_t leftMask)
{
    uint8_t tableY = 0;

    LCD_SegmentSelection(LCD_TOP_SEGMENT);
    LCD_SetY(FONT_HEIGHT);
    LCD_SetX(x);

    for (uint8_t y = FONT_HEIGHT; y < LCD_HEIGHT; y += GAME_PIXEL_HEIGHT)
    {
        uint16_t gameRow = tetrisGame->table[tableY];
        uint8_t lcdRow = 0;
        if (gameRow & rightMask)
            lcdRow = 0x0F;
        if (gameRow & leftMask)
            lcdRow |= 0xF0;
        
        if (y == 63)
        {
            LCD_WriteData(lcdRow);
            LCD_SegmentSelection(LCD_BOTTOM_SEGMENT);
            LCD_SetX(x);
            LCD_SetY(0);
            LCD_WriteData(lcdRow);
            LCD_WriteData(lcdRow);
            LCD_WriteData(lcdRow);
            LCD_WriteData(lcdRow);
        }
        else
        {
            for (uint8_t i = 0; i < GAME_PIXEL_HEIGHT; ++i)
                LCD_WriteData(lcdRow);
        }

        ++tableY;
    }
}

static void DrawHiMarker(void)
{
    LCD_SegmentSelection(LCD_TOP_SEGMENT);
    LCD_SetX(3);
    LCD_SetY(0);
    for (uint8_t y = 0; y < FONT_HEIGHT; ++y)
        LCD_WriteData(Font_hi[y] >> 2);
}

void DrawTetris(Tetris_Game *tetrisGame)
{
    uint16_t leftMask = 0b0000000000000010;
    uint16_t rightMask = 0b0000000000000001;

    for (uint8_t x = 0; x < LCD_NUM_PAGES; ++x)
    {
        DrawTetrisGameColumn(tetrisGame, x, rightMask, leftMask);
        leftMask <<= 2;
        rightMask <<= 2;
    }
}

void DrawCurrentScore(Tetris_Game *tetrisGame)
{
    uint8_t scoreDigits[NUM_DIGITS];
    GetDigits(tetrisGame->currentScore, scoreDigits);

    LCD_SegmentSelection(LCD_TOP_SEGMENT);
    LCD_SetX(7);
    LCD_SetY(0);
    for (uint8_t y = 0; y < FONT_HEIGHT; ++y)
    {
        uint8_t lcdData = Font_digits[scoreDigits[0]][y] | (Font_digits[scoreDigits[1]][y] >> 4);
        LCD_WriteData(lcdData);
    }

    LCD_SetX(6);
    LCD_SetY(0);
    for (uint8_t y = 0; y < FONT_HEIGHT; ++y)
    {
        uint8_t lcdData = Font_digits[scoreDigits[2]][y] | (Font_digits[scoreDigits[3]][y] >> 4);
        LCD_WriteData(lcdData);
    }

    LCD_SetX(5);
    LCD_SetY(0);
    for (uint8_t y = 0; y < FONT_HEIGHT; ++y)
    {
        uint8_t lcdData = Font_digits[scoreDigits[4]][y];
        LCD_WriteData(lcdData);
    }
}

void DrawHighscore(uint16_t highscore)
{
    DrawHiMarker();

    uint8_t scoreDigits[NUM_DIGITS];
    GetDigits(highscore, scoreDigits);

    LCD_SegmentSelection(LCD_TOP_SEGMENT);
    LCD_SetX(2);
    LCD_SetY(0);
    for (uint8_t y = 0; y < FONT_HEIGHT; ++y)
    {
        uint8_t lcdData = Font_digits[scoreDigits[0]][y] >> 4;
        LCD_WriteData(lcdData << 1);
    }

    LCD_SetX(1);
    LCD_SetY(0);
    for (uint8_t y = 0; y < FONT_HEIGHT; ++y)
    {
        uint8_t lcdData = Font_digits[scoreDigits[1]][y] | (Font_digits[scoreDigits[2]][y] >> 4);
        LCD_WriteData(lcdData << 1);
    }

    LCD_SetX(0);
    LCD_SetY(0);
    for (uint8_t y = 0; y < FONT_HEIGHT; ++y)
    {
        uint8_t lcdData = Font_digits[scoreDigits[3]][y] | (Font_digits[scoreDigits[4]][y] >> 4);
        LCD_WriteData(lcdData << 1);
    }
}

static void DrawHighscoreText(void)
{
    uint8_t const baseX = 5;
    uint8_t const baseY = 56;

    LCD_SegmentSelection(LCD_TOP_SEGMENT);
    LCD_SetX(baseX);
    LCD_SetY(baseY);

    for (uint8_t y = 0; y < FONT_HEIGHT; ++y)
        LCD_WriteData(Font_hi[y]);


    for (uint8_t x = 0; x < 3; ++x)
    {
        LCD_SetY(baseY);
        LCD_SetX(baseX - x - 1);
        for (uint8_t y = 0; y < FONT_HEIGHT; ++y)
            LCD_WriteData(Font_score[x][y]);
    }
}

typedef enum
{
    NUM_FLASHES = 6,
    FLASH_DELAY = 600,
} Flashing;

void FlashVictoriously(void)
{
    LCD_SegmentSelection(LCD_BOTH_SEGMENTS);
    LCD_Clear();
    DrawHighscoreText();

    for (uint8_t i = 0; i < NUM_FLASHES; ++i)
    {
        __delay_ms(FLASH_DELAY);
        LCD_TurnOff();
        __delay_ms(FLASH_DELAY);
        LCD_TurnOn();
    }
}
