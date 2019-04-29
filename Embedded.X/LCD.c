#include "LCD.h"

#define LCD_TRIS TRISA
#define LCD_DATA PORTA
#define LCD_nCS1 RC1
#define LCD_nCS2 RC0
#define LCD_DnI  RC2
#define LCD_RnW  RC3
#define LCD_E    RD0
#define LCD_nRST RD1

typedef enum {
    LCD_WRITE_INSTRUCTION = 0,
    LCD_WRITE_DATA = 1,
} LCD_WriteMode;

typedef enum {
    LCD_BUSY_FLAG = 0x80,
    LCD_RESET_FLAG = 0x10,
} LCD_StatusFlags;

static uint8_t LCD_IsBusy(void)
{
    uint8_t status = LCD_ReadStatus();
    return (status & LCD_BUSY_FLAG) || (status & LCD_RESET_FLAG);
}

static void LCD_BlockWhileBusy(void)
{
    while (LCD_IsBusy())
    {
    }
}

static void LCD_Write(LCD_WriteMode mode, uint8_t data)
{
    LCD_BlockWhileBusy();

    LCD_TRIS = 0;
    LCD_RnW = 0;
    LCD_DnI = mode;
    LCD_DATA = data;
    LCD_E = 1;
    NOP(); // This is on the safe side - shouldn't be required
    LCD_E = 0;
}

void LCD_SetupPorts(void)
{
    ANSELH = 0;
    TRISB = 0xFF;
    WPUB = 0xFF;
    nRBPU = 0;
    PORTB = 0;
    
    TRISD = 0;
    PORTD = 0;
    TRISC = 0;
    PORTC = 0;
    
    ANSEL = 0;
    TRISA = 0;
    PORTA = 0;
}

void LCD_Reset()
{
    LCD_nRST = 0;
    NOP();
    NOP();
    NOP();
    NOP(); // The NOP's are on the safe side - shouldn't be required
    LCD_nRST = 1;
    NOP();
    LCD_SetX(0);
    LCD_SetY(0);
    LCD_SetZ(0);
}

uint8_t LCD_ReadStatus(void)
{
    LCD_TRIS = 0xFF;
    LCD_RnW = 1;
    LCD_DnI = 0;
    LCD_E = 1;
    uint8_t status = LCD_DATA;
    LCD_E = 0;
    return status;
}

uint8_t LCD_ReadData(void)
{
    LCD_BlockWhileBusy();

    LCD_DnI = 1;
    LCD_E = 1;
    uint8_t data = LCD_DATA;
    LCD_E = 0;
    return data;
}

void LCD_WriteData(uint8_t data)
{
    LCD_Write(LCD_WRITE_DATA, data);
}

void LCD_SegmentSelection(LCD_Segments segments)
{
    if (segments & LCD_TOP_SEGMENT)
        LCD_nCS2 = 0;
    else
        LCD_nCS2 = 1;

    if (segments & LCD_BOTTOM_SEGMENT)
        LCD_nCS1 = 0;
    else
        LCD_nCS1 = 1;
}

void LCD_TurnOn(void)
{
    LCD_Write(LCD_WRITE_INSTRUCTION, 0x3F);
}

void LCD_TurnOff(void)
{
    LCD_Write(LCD_WRITE_INSTRUCTION, 0x3E);
}

void LCD_SetY(uint8_t y)
{
    LCD_Write(LCD_WRITE_INSTRUCTION, 0x40 | y);
}

void LCD_SetX(uint8_t x)
{
    LCD_Write(LCD_WRITE_INSTRUCTION, 0xB8 | x);
}

void LCD_SetZ(uint8_t z)
{
    LCD_Write(LCD_WRITE_INSTRUCTION, 0xC0 | z);
}

void LCD_Clear(void)
{
    for (uint8_t x = 0; x < LCD_NUM_PAGES; ++x)
    {
        LCD_SetX(x);
        LCD_SetY(0);
        for (uint8_t y = 0; y < LCD_SEGMENT_HEIGHT; ++y)
            LCD_WriteData(0);
    }
}

