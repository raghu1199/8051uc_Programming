#include<reg52.h>
sfr lcdp=0x80;
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<=1275;j++);
}
void lcd_cmd(unsigned char cmd)
{
	lcdp=cmd;
	rs=0;
	rw=0;
	en=1;
	delay(5);
	en=0;
}
void lcd_init(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0c);
	lcd_cmd(0x80);
}
void lcd_dat(unsigned char dat)
{
	lcdp=dat;
	rs=1;
	rw=0;
	en=1;
	delay(5);
	en=0;
}
void custom_char()
{
	lcd_cmd(0x40);
	lcd_dat(0x00);
	lcd_dat(0x0e);
	lcd_dat(0x1d);
	lcd_dat(0x1e);
	lcd_dat(0x1f);
	lcd_dat(0x0e);
	lcd_dat(0x00);
	lcd_dat(0x00);
	lcd_cmd(0x80);
	lcd_dat(0);
	
	lcd_cmd(0x48);
	lcd_dat(0x00);
	lcd_dat(0x00);
	lcd_dat(0x00);
	lcd_dat(0x04);
	lcd_dat(0x00);
	lcd_dat(0x00);
	lcd_dat(0x00);
	lcd_dat(0x00);
	lcd_cmd(0x82);
	lcd_dat(1);
}
void lcd_scroll(int len)
{
	int i=0;
	while(1)
	{
		for(i=0;i<len;i++)
		{
			lcd_cmd(0x1c);
			delay(20);
		}
	}
}
void main()
{
	lcd_init();
	custom_char();
	lcd_scroll(3);
	while(1);
}