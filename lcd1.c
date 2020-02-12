#include<reg52.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
sfr lcdp=0x80;
void lcd_init(void);
void lcd_cmd(unsigned char );
void lcd_data(unsigned char);
void delay(int);
void main()
{
	lcd_init();
	lcd_data('A');
	while(1);
}
void lcd_init(void)
{
	lcd_cmd(0x01);
	lcd_cmd(0x02);
	lcd_cmd(0x0c);
	lcd_cmd(0x38);
	lcd_cmd(0x80);
}
void lcd_cmd(unsigned char cmd)
{
	lcdp=cmd;
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void lcd_data(unsigned char data1)
{
	lcdp=data1;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<=1000;j++);
}