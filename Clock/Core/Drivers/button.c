#include "button.h"
#include "stm32f4xx_hal.h"
#include "main.h"

extern RTC_HandleTypeDef hrtc; 
extern void SetTime(RTC_TimeTypeDef *sTime, RTC_DateTypeDef *sDate);

static RTC_TimeTypeDef sTime;
static RTC_DateTypeDef sDate;

void increaseButtonPressed() {
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); 

    if (++sTime.Minutes >= 60) {
        sTime.Minutes = 0;
        sTime.Hours = (sTime.Hours + 1) % 24;
    }
    sTime.Seconds = 0;
    SetTime(&sTime, &sDate);
}

void decreaseButtonPressed() {
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

    if (sTime.Minutes == 0) {
        sTime.Minutes = 59;
        sTime.Hours = (sTime.Hours == 0) ? 23 : sTime.Hours - 1;
    } else {
        sTime.Minutes--;
    }
    sTime.Seconds = 0;
    SetTime(&sTime, &sDate);
}

void Button_Scan() {
    if (HAL_GPIO_ReadPin(GPIOB, increaseButton_Pin) == GPIO_PIN_SET) {
        increaseButtonPressed();
    }
    if (HAL_GPIO_ReadPin(GPIOB, decreaseButton_Pin) == GPIO_PIN_SET) {
        decreaseButtonPressed();
    }
}   