#ifndef __BSP_GPIO_LIGHT_H
#define __BSP_GPIO_LIGHT_H

#include "stm32f10x.h"


/* 定义KEY连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的key引脚 */
// LIGHT DO
#define LIGHT_DO_GPIO_PORT    			GPIOA			                /* GPIO端口 */
#define LIGHT_DO_GPIO_CLK_PORT 	    RCC_APB2Periph_GPIOA			/* GPIO端口时钟 */
#define LIGHT_DO_GPIO_PIN			    GPIO_Pin_11	       				/* 连接到GPIO */



void LIGHT_GPIO_Config(void);
BitAction LIGHT_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
#endif /* __BSP_GPIO_LIGHT_H  */
