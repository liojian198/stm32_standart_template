/**
  ******************************************************************************
  * @file       main.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      光敏传感器
  ******************************************************************************
  * @attention
  *
  * 实验平台  ：野火 STM32F103C8T6-STM32开发板 
  * 论坛      ：http://www.firebbs.cn
  * 官网      ：https://embedfire.com/
  * 淘宝      ：https://yehuosm.tmall.com/
  *
  ******************************************************************************
  */

#include "main.h"
#include "stm32f10x.h"
#include "delay/bsp_delay.h"
#include "led/bsp_gpio_led.h"
#include "light/bsp_gpio_light.h"

/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void)
{
    LED_GPIO_Config();
		LIGHT_GPIO_Config();

    while(1)
    {
        if(LIGHT_Scan(LIGHT_DO_GPIO_PORT, LIGHT_DO_GPIO_PIN) == Bit_RESET){
					LED_OFF(LED4_GPIO_PORT,LED4_GPIO_PIN,LED_LOW_TRIGGER);
				}else {
					LED_ON(LED4_GPIO_PORT,LED4_GPIO_PIN,LED_LOW_TRIGGER);
				}
				
    }
        
}

