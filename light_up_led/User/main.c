


#include "stm32f10x.h"


int main(void)
{
	
	GPIO_InitTypeDef gpio_init= {0};
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//开启端口时钟
	GPIO_SetBits(GPIOA, GPIO_Pin_1); //让端口引脚输出1，使得灯灭
	GPIO_SetBits(GPIOA, GPIO_Pin_2); //让端口引脚输出2，使得灯灭
	GPIO_SetBits(GPIOA, GPIO_Pin_3); //让端口引脚输出3，使得灯灭
	
	gpio_init.GPIO_Pin = GPIO_Pin_1;
	gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_init); //配置端口引脚的模式
	
	gpio_init.GPIO_Pin = GPIO_Pin_2;
	gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_init); //配置端口引脚的模式
	
	gpio_init.GPIO_Pin = GPIO_Pin_3;
	gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_init); //配置端口引脚的模式
	
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_1); //让端口引脚输出0，使得灯亮
	GPIO_ResetBits(GPIOA, GPIO_Pin_2); //让端口引脚输出0，使得灯亮
	GPIO_ResetBits(GPIOA, GPIO_Pin_3); //让端口引脚输出0，使得灯亮
																										 
	
	
	while(1);
	
}
