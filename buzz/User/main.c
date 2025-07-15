/**
  ******************************************************************************
  * @file       main.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief      流水灯
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
#include "key/bsp_gpio_key.h"
#include "buzz/bsp_gpio_buzz.h"

/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void)
{
    KEY_GPIO_Config();
		BUZZ_GPIO_Config();

    while(1)
    {
        if(KEY_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN, KEY_HIGHT_TRIGGER) == KEY_DOWN){
					BUZZ_TOGGLE(BUZZ_GPIO_PORT,BUZZ_GPIO_PIN);
				}
				
    }
        
}

