
#include "door.h"
#include "common.h"


#define DOOR_GPIO_CLK        RCC_AHB1Periph_GPIOG//207 RCC_APB2Periph_GPIOD(103)
#define DOOR_GPIO_PORT       GPIOG

#define DOOR_PIN1            GPIO_Pin_2




void DOOR_HW_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(DOOR_GPIO_CLK, ENABLE);

    // Configure  pins:
    GPIO_InitStructure.GPIO_Pin = DOOR_PIN1 ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(DOOR_GPIO_PORT, &GPIO_InitStructure);

    // Set Default
    GPIO_ResetBits(DOOR_GPIO_PORT,DOOR_PIN1);
	  //GPIO_SetBits(DOOR_GPIO_PORT,DOOR_PIN1);
}

void DOOR_Set(uint8_t cmd)
{
    if(cmd)
    {
        //GPIO_ResetBits(DOOR_GPIO_PORT,DOOR_PIN1); //开门低电平
        GPIO_SetBits(DOOR_GPIO_PORT,DOOR_PIN1);
    }
    else
    {
        //GPIO_SetBits(DOOR_GPIO_PORT,DOOR_PIN1);
				GPIO_ResetBits(DOOR_GPIO_PORT,DOOR_PIN1); 
    }
}


void TEST_DOOR(void)
{
    DOOR_HW_Init();

    while(1)
    {
        DOOR_Set(1);

        delay_ms(500);
        DOOR_Set(0);
        delay_ms(500);
    }

}