#include<reg52.h>
#define lcdp P0
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void delay(int);
void lcd_string(unsigned char a[]);
void main()
{
	unsigned char alph[]="RAHUL";
	lcd_init();
	lcd_string(alph);
	while(1);
}
void lcd_init(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0c);
	lcd_cmd(0x80);
}
void lcd_string(unsigned char a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		lcd_data(a[i]);
		i++;
		delay(5);
	}
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
void lcd_data(unsigned char data1)
{
	lcdp=data1;
	rs=1;
	rw=0;
	en=1;
	delay(5);
	en=0;
}
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<=1275;j++);
}