#include "uart_stm32f466.h"
#include "stm32f4xx_hal.h"
#include "main.h"

extern UART_HandleTypeDef huart2;

static void MX_USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}

void platform_uart_init(void) {
      MX_USART2_UART_Init();
}

void platform_uart_write_byte(uint8_t byte) {
    HAL_UART_Transmit(&huart2, &byte, 1, HAL_MAX_DELAY);
}