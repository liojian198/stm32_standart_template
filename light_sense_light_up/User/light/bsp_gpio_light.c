/**
  ******************************************************************************
  * @file    bsp_gpio_led.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief   
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
  
  
#include "light/bsp_gpio_light.h"
#include "delay/bsp_delay.h"


/**
 * @brief  初始化控制LED的IO
 * @param  无
 * @retval 无
 */
void LIGHT_GPIO_Config(void)
{
    GPIO_InitTypeDef gpio_initstruct = {0};
		//key1
		RCC_APB2PeriphClockCmd(LIGHT_DO_GPIO_CLK_PORT, ENABLE);
		GPIO_SetBits(LIGHT_DO_GPIO_PORT, LIGHT_DO_GPIO_PIN);
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_initstruct.GPIO_Pin = LIGHT_DO_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LIGHT_DO_GPIO_PORT,&gpio_initstruct);
		
}

//基础检测按键
BitAction LIGHT_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == Bit_RESET)
	{
		return Bit_RESET;
	}
	else {
		return Bit_SET;
	}
	
}
