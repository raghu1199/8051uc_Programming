#include<reg52.h>
#include "lcd4bit.h"
sbit OE=P2^1;
sbit ST=P2^2;
sbit INTR=P2^3;
sfr adc_data=0x80;
void main()
{
	unsigned char x;
	adc_data=0xff;
	INTR=1;
	OE=1;
	ST=1;
	lcd_init();
	lcd_string("ADC OUT: ");
	lcd_display('A');
	while(1)
	{
		ST=0;
		ST=1;				//low to high pulse
		while(INTR==1);
		delay(5);
		OE=0;
		x=adc_data;
		lcd_cmd(0x89);
		bcd_conv(x);
		OE=1;
	}
}