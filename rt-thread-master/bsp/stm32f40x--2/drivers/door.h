#ifndef __DOOR_H__
#define __DOOR_H__

#include "stm32f4xx.h"

void DOOR_HW_Init(void);

void DOOR_Set(uint8_t cmd);

#endif
