#ifndef __BSP_GPIO_BUZZ_H
#define __BSP_GPIO_BUZZ_H

#include "stm32f10x.h"


/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的LED引脚 */
// R_LED
#define BUZZ_GPIO_PORT    			GPIOA			                /* GPIO端口 */
#define BUZZ_GPIO_CLK_PORT 	    RCC_APB2Periph_GPIOA			/* GPIO端口时钟 */
#define BUZZ_GPIO_PIN			    GPIO_Pin_6	       				/* 连接到GPIO */


typedef enum 
{
	BUZZ_LOW_TRIGGER = 0, 
	BUZZ_HIGHT_TRIGGER = 1
} BUZZ_TriggerRLevel;


void BUZZ_GPIO_Config(void);
void BUZZ_TOGGLE(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void BUZZ_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BUZZ_TriggerRLevel level);
void BUZZ_OFF(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BUZZ_TriggerRLevel level);
#endif /* __BSP_GPIO_BUZZ_H  */
