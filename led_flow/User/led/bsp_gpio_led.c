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
}
