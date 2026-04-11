#include "i2c_interface.h"
#include "main.h"      
#include <stdint.h>    

#define LCD_ADDR (0x27)
#define PIN_RS (1 << 0)
#define PIN_EN (1 << 2)
#define BACKLIGHT (1 << 3)

void LCD_Init(void);
void LCD_Clear(void); 
void LCD_Send_String(const char *str);
void LCD_Write_Nibble(uint8_t nibble, uint8_t rs);
void LCD_Send_Byte(uint8_t byte, uint8_t rs);