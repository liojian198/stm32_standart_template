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
  
  
#include "key/bsp_gpio_key.h"
#include "delay/bsp_delay.h"


/**
 * @brief  初始化控制LED的IO
 * @param  无
 * @retval 无
 */
void KEY_GPIO_Config(void)
{
    GPIO_InitTypeDef gpio_initstruct = {0};
		//key1
		RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK_PORT, ENABLE);
		GPIO_SetBits(KEY1_GPIO_PORT, KEY1_GPIO_PIN);
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_initstruct.GPIO_Pin = KEY1_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY1_GPIO_PORT,&gpio_initstruct);
		
		//key2
		RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK_PORT, ENABLE);
		GPIO_SetBits(KEY2_GPIO_PORT, KEY2_GPIO_PIN);
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_initstruct.GPIO_Pin = KEY2_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY2_GPIO_PORT,&gpio_initstruct);
		
		//自定义扩展按键
		
		//key3
		RCC_APB2PeriphClockCmd(KEY3_GPIO_CLK_PORT, ENABLE);
		GPIO_SetBits(KEY3_GPIO_PORT, KEY3_GPIO_PIN);
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IPD;
    gpio_initstruct.GPIO_Pin = KEY3_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY3_GPIO_PORT,&gpio_initstruct);
		
		
		//key4
		RCC_APB2PeriphClockCmd(KEY4_GPIO_CLK_PORT, ENABLE);
		GPIO_SetBits(KEY4_GPIO_PORT, KEY4_GPIO_PIN);
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IPU;
    gpio_initstruct.GPIO_Pin = KEY4_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY4_GPIO_PORT,&gpio_initstruct);
    
		//key5
		RCC_APB2PeriphClockCmd(KEY5_GPIO_CLK_PORT, ENABLE);
		GPIO_SetBits(KEY5_GPIO_PORT, KEY5_GPIO_PIN);
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IPU;
    gpio_initstruct.GPIO_Pin = KEY5_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY5_GPIO_PORT,&gpio_initstruct);
		
		
		//key6
		RCC_APB2PeriphClockCmd(KEY6_GPIO_CLK_PORT, ENABLE);
		GPIO_SetBits(KEY6_GPIO_PORT, KEY6_GPIO_PIN);
    //配置io模式 推挽模式，50m
    gpio_initstruct.GPIO_Mode = GPIO_Mode_IPU;
    gpio_initstruct.GPIO_Pin = KEY6_GPIO_PIN;
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY6_GPIO_PORT,&gpio_initstruct);
		
}

//基础检测按键
KEY_Status KEY_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, KEY_TriggerRLevel key_press_status) {
	
	if( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == key_press_status){
		Rough_Delay_Ms(20);
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == key_press_status);
		Rough_Delay_Ms(20);
		return KEY_DOWN;
	} else {
		return KEY_UP;
	}
}
