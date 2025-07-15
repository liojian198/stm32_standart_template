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
  
  
#include "led/bsp_gpio_led.h"





/**
 * @brief  初始化控制LED的IO
 * @param  无
 * @retval 无
 */
void LED_GPIO_Config(void)
{
    GPIO_InitTypeDef gpio_initstruct = {0};
    
		#if 0
    //开启端口时钟
    RCC_APB2PeriphClockCmd(R_LED_GPIO_CLK_PORT,ENABLE);
    RCC_APB2PeriphClockCmd(G_LED_GPIO_CLK_PORT,ENABLE);
    RCC_APB2PeriphClockCmd(B_LED_GPIO_CLK_PORT,ENABLE);
    
    
    //关闭灯
    GPIO_SetBits(R_LED_GPIO_PORT,R_LED_GPIO_PIN);
    GPIO_SetBits(G_LED_GPIO_PORT,G_LED_GPIO_PIN);
    GPIO_SetBits(B_LED_GPIO_PORT,B_LED_GPIO_PIN);

    
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = R_LED_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(R_LED_GPIO_PORT,&gpio_initstruct);
    
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = G_LED_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(G_LED_GPIO_PORT,&gpio_initstruct);
    
    gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin = B_LED_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(B_LED_GPIO_PORT,&gpio_initstruct);
		#endif
		
		//用户自定义按键LED
		//LCD4
		RCC_APB2PeriphClockCmd(LED4_GPIO_CLK_PORT,ENABLE);
		GPIO_SetBits(LED4_GPIO_PORT,LED4_GPIO_PIN);
		
		gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin =LED4_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED4_GPIO_PORT,&gpio_initstruct);
		
		#if 0
		//LCD13
		RCC_APB2PeriphClockCmd(LED13_GPIO_CLK_PORT,ENABLE);
		GPIO_ResetBits(LED13_GPIO_PORT,LED13_GPIO_PIN);
		
		gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin =LED13_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED13_GPIO_PORT,&gpio_initstruct);
		
		//LCD14
		RCC_APB2PeriphClockCmd(LED14_GPIO_CLK_PORT,ENABLE);
		GPIO_ResetBits(LED14_GPIO_PORT,LED14_GPIO_PIN);
		
		gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio_initstruct.GPIO_Pin =LED14_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED14_GPIO_PORT,&gpio_initstruct);
		#endif
}

void LED_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, LED_TriggerRLevel level) {
	
	if(level == LED_LOW_TRIGGER) 
	{
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	} else {
		GPIO_SetBits(GPIOx, GPIO_Pin);
	}	

}

void LED_OFF(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, LED_TriggerRLevel level) {
	
	if(level == LED_LOW_TRIGGER) 
	{
		GPIO_SetBits(GPIOx, GPIO_Pin);
	} else {
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	}	
}

//翻转
void LED_TOGGLE(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	
	GPIOx->ODR ^= GPIO_Pin;
}

	
