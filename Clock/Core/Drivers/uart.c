#include "uart.h"
#include "uart_stm32f466.h"

void uart_init(void) {
      platform_uart_init();
}

void uart_write(const char *str) {
    while (*str) {
        platform_uart_write_byte((uint8_t)(*str));
        str++;
    };
}

void uart_write_byte(uint8_t byte) {
    platform_uart_write_byte(byte);
}