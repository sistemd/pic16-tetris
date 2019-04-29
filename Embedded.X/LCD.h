#pragma once

#include <xc.h>
#include <stdint.h>

typedef enum {
    LCD_NO_SEGMENT = 0,
    LCD_BOTTOM_SEGMENT = 1,
    LCD_TOP_SEGMENT = 2,
    LCD_BOTH_SEGMENTS = LCD_BOTTOM_SEGMENT | LCD_TOP_SEGMENT,
} LCD_Segments;

typedef enum {
    LCD_WIDTH = 64,
    LCD_HEIGHT = 128,
    LCD_NUM_PAGES = 8,
    LCD_SEGMENT_HEIGHT = 64,
} LCD_Dimensions;

extern void LCD_SetupPorts(void);

extern void LCD_Reset(void);

extern uint8_t LCD_ReadStatus(void);

extern uint8_t LCD_ReadData(void);

extern void LCD_WriteData(uint8_t data);

extern void LCD_SegmentSelection(LCD_Segments segments);

extern void LCD_TurnOn(void);

extern void LCD_TurnOff(void);

extern void LCD_SetY(uint8_t y);

extern void LCD_SetX(uint8_t x);

extern void LCD_SetZ(uint8_t z);

extern void LCD_Clear(void);

