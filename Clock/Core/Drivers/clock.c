#include "stm32f4xx_hal.h"
#include "clock.h"
#include "main.h"

extern RTC_HandleTypeDef hrtc;
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;

void RTC_ReadTime(void)
{
  HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
  HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
}

void SetTime(RTC_TimeTypeDef *time, RTC_DateTypeDef *date) {
  HAL_RTC_SetTime(&hrtc, time, RTC_FORMAT_BIN);
  HAL_RTC_SetDate(&hrtc, date, RTC_FORMAT_BIN);
}