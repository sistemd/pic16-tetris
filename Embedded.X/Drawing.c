#include "Drawing.h"
#include "LCD.h"

enum
{
    SCORE_SPACE = 8,
};

typedef enum {
    PIXEL_WIDTH = LCD_WIDTH / TETRIS_TABLE_WIDTH,
    PIXEL_HEIGHT = (LCD_HEIGHT - SCORE_SPACE) / TETRIS_TABLE_HEIGHT,
} PixelSize;

static void DrawRow(uint16_t gameRow, uint16_t rightMask, uint16_t leftMask)
{
}

void RedrawTetrisOnLCD(Tetris_Game *tetrisGame)
{
    /* Show the scores */
    /* Fix inconsistent naming between x/pages */
    uint16_t leftMask = 0b0000000000000010;
    uint16_t rightMask = 0b0000000000000001;

    for (uint8_t x = 0; x < LCD_NUM_PAGES; ++x)
    {
        LCD_SegmentSelection(LCD_TOP_SEGMENT);
        LCD_SetX(x);
        LCD_SetY(SCORE_SPACE);

        for (uint8_t y = SCORE_SPACE, tableY = 0; y < LCD_HEIGHT; y += PIXEL_HEIGHT)
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
                for (uint8_t i = 0; i < PIXEL_HEIGHT; ++i)
                    LCD_WriteData(lcdRow);
            }

            ++tableY;
        }

        leftMask <<= 2;
        rightMask <<= 2;
    }
}