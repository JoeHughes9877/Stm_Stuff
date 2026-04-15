#include "lcd_hd44780.h" 
#include "i2c_interface.h"
#include "main.h"
#include <stdint.h>

void LCD_Init() {
    HAL_Delay(50); //wake up 

    // Set 4-bit mode
    LCD_Write_Nibble(0x03, 0);
    HAL_Delay(5);
    LCD_Write_Nibble(0x03, 0);
    HAL_Delay(1);
    LCD_Write_Nibble(0x03, 0);
    HAL_Delay(1);

    LCD_Write_Nibble(0x02, 0); 
    HAL_Delay(1);

    // 4 bit mode in 2 lines 5x8 dots
    LCD_Send_Byte(0x28, 0);
    HAL_Delay(1);
    LCD_Send_Byte(0x0C, 0); 
    HAL_Delay(1);
    LCD_Send_Byte(0x06, 0); 
    HAL_Delay(1);
    
    LCD_Clear();
}

void LCD_Clear() {
    LCD_Send_Byte(0x01, 0); 
    HAL_Delay(2); 
}

void LCD_Send_String(const char *str) {
    while (*str) {
        LCD_Send_Byte(*str++, 1); 
    }
}

void LCD_Send_Byte(uint8_t byte, uint8_t rs) {
    LCD_Write_Nibble(byte >> 4, rs);
    LCD_Write_Nibble(byte & 0x0F, rs);
}

void LCD_Write_Nibble(uint8_t nibble, uint8_t rs) {
    uint8_t data = (nibble << 4) | rs | BACKLIGHT | PIN_EN;
    I2C_Interface_Write(LCD_ADDR, data);
    HAL_Delay(1); 

    data &= ~PIN_EN; 
    I2C_Interface_Write(LCD_ADDR, data);
    HAL_Delay(1); 
}

void LCD_Set_Cursor(uint8_t row, uint8_t col)
{
    uint8_t address = 0;

    switch (row)
    {
        case 0:
            address = 0x00;
            break;
        case 1:
            address = 0x40;
            break;
        case 2:
            address = 0x14;
            break;
        case 3:
            address = 0x54;
            break;
        default:
            return;
    }
    address += col;
    LCD_Send_Byte(0x80 | address, 0);
}