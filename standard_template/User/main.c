



int main(void)
{
	unsigned int* led_rcc = (unsigned int*) (0x40021000+0x18); //灯具时钟开关地址
	unsigned int* led_config = (unsigned int*) (0x40010800+0x00);
	unsigned int* led_output = (unsigned int*) (0x40010800+0x0C);
	
	*led_rcc |=0x4;
	*led_config |= 0x3330;
	*led_output |= 0xE;
	*led_output &= ~0xE; //&=~ 通常用来复0，|= 通常用来置1
	
	while(1);
	
}
