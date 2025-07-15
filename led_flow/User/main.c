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

/**
  * @brief  主函数
  * @param  无 
  * @note   无
  * @retval 无
  */
int main(void)
{
    uint32_t time_temp  = 3000;
    
    LED_GPIO_Config();

    while(1)
    {
        R_LED_ON_ONLY;
        Rough_Delay_Ms(time_temp);
        
        G_LED_ON_ONLY;
        Rough_Delay_Ms(time_temp);
        
        B_LED_ON_ONLY;
        Rough_Delay_Ms(time_temp);
        
        R_G_B_ALL_ON;
        Rough_Delay_Ms(time_temp);
        R_G_B_ALL_OFF;
        Rough_Delay_Ms(time_temp);
        
        R_G_B_ALL_ON;
        Rough_Delay_Ms(time_temp);
        R_G_B_ALL_OFF;
        Rough_Delay_Ms(time_temp);
        
        R_G_B_ALL_ON;
        Rough_Delay_Ms(time_temp);
        R_G_B_ALL_OFF;
        Rough_Delay_Ms(time_temp);
        
    
    }
        
}

