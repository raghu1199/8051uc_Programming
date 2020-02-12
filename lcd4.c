#include<reg52.h>
#include<string.h>
sfr lcdp=0x80;
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
unsigned char alph[]="HYY THIS IS A TEST!!!!OF SCROLLING.";
int length;
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
void lcd_scroll(int len)
{
	int i=0;
	while(1)
	{
		for(i=0;i<len;i++)
		{
			lcd_cmd(0x18);
			delay(20);
		}
	}
}
void lcd_display(unsigned char data1)
{
	lcdp=data1;
	rs=1;
	rw=0;
	en=1;
	delay(5);
	en=0;
}
void lcd_string(unsigned char a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		lcd_display(a[i]);
		i++;
	}
}
void main()
{
	lcd_init();
	length=strlen(alph);
	lcd_string(alph);
	lcd_scroll(length);
	while(1);
}