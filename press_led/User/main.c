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
#include "led/bsp_gpio_led.h"
#include "key/bsp_gpio_key.h"

/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void)
{
    LED_GPIO_Config();
		KEY_GPIO_Config();

    while(1)
    {
        if(KEY_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN, KEY_HIGHT_TRIGGER) == KEY_DOWN){
					LED_TOGGLE(R_LED_GPIO_PORT,R_LED_GPIO_PIN);
				}
				if(KEY_Scan(KEY2_GPIO_PORT, KEY2_GPIO_PIN, KEY_HIGHT_TRIGGER) == KEY_DOWN){
					LED_TOGGLE(G_LED_GPIO_PORT,G_LED_GPIO_PIN);
				}
				if(KEY_Scan(KEY3_GPIO_PORT, KEY3_GPIO_PIN, KEY_HIGHT_TRIGGER) == KEY_DOWN){
					LED_TOGGLE(B_LED_GPIO_PORT,B_LED_GPIO_PIN);
				}
				if(KEY_Scan(KEY4_GPIO_PORT, KEY4_GPIO_PIN, KEY_LOW_TRIGGER) == KEY_DOWN){
					LED_TOGGLE(LED4_GPIO_PORT,LED4_GPIO_PIN);
				}
				if(KEY_Scan(KEY5_GPIO_PORT, KEY5_GPIO_PIN, KEY_LOW_TRIGGER) == KEY_DOWN){
					LED_TOGGLE(LED13_GPIO_PORT,LED13_GPIO_PIN);
				}
				if(KEY_Scan(KEY6_GPIO_PORT, KEY6_GPIO_PIN, KEY_LOW_TRIGGER) == KEY_DOWN){
					LED_TOGGLE(LED14_GPIO_PORT,LED14_GPIO_PIN);
				}
    }
        
}

