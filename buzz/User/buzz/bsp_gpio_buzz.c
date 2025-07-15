/**
  ******************************************************************************
  * @file    bsp_gpio_led.c
  * @author     embedfire
  * @version     V1.0
  * @date        2024
  * @brief   led应用函数接口
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
  
  
#include "buzz/bsp_gpio_buzz.h"


/**
 * @brief  初始化控制LED的IO
 * @param  无
 * @retval 无
 */
void BUZZ_GPIO_Config(void)
{
    GPIO_InitTypeDef gpio_initstruct = {0};
    
    //开启端口时钟
    RCC_APB2PeriphClockCmd(BUZZ_GPIO_CLK_PORT,ENABLE);
    GPIO_ResetBits(BUZZ_GPIO_PORT,BUZZ_GPIO_PIN);
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = BUZZ_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BUZZ_GPIO_PORT,&gpio_initstruct);
   
}

void BUZZ_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BUZZ_TriggerRLevel level) {
	
	if(level == BUZZ_LOW_TRIGGER) 
	{
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	} else {
		GPIO_SetBits(GPIOx, GPIO_Pin);
	}	

}

void BUZZ_OFF(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BUZZ_TriggerRLevel level) {
	
	if(level == BUZZ_LOW_TRIGGER) 
	{
		GPIO_SetBits(GPIOx, GPIO_Pin);
	} else {
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	}	
}

//翻转
void BUZZ_TOGGLE(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	
	GPIOx->ODR ^= GPIO_Pin;
}

	
