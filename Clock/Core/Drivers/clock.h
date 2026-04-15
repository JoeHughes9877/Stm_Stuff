#ifndef RTC_H_
#define RTC_H_

#include <stdint.h>

void RTC_ReadTime(void);
void SetTime(RTC_TimeTypeDef *time, RTC_DateTypeDef *date);

#endif 