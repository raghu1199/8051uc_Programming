#include<reg52.h>
sfr lcdp=0x90;
sbit rs=P2^4;
sbit rw=P2^5;
sbit en=P2^6;
int a[10];
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<=1275;j++);
}
void lcd_cmd(unsigned char cmd)
{
	lcdp=(lcdp & 0x0F) | (cmd & 0xF0);
	rs=0;
	rw=0;
	en=1; 
	delay(5);
	en=0;
	delay(5);
	
	lcdp= (lcdp & 0x0F) | (cmd << 4);
	en=1;
	delay(5);
	en=0;
	delay(5);
}
void lcd_display(unsigned char data1)
{
	lcdp=(lcdp & 0x0F) | (data1 & 0xF0);
	rs=1;
	rw=0;
	en=1;
	delay(5);
	en=0;
	delay(5);
	
	lcdp=(lcdp & 0x0F) | (data1 << 4);
	en=1;
	delay(5);
	en=0;
	delay(5);
}
void lcd_string(unsigned char a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		lcd_display(a[i]);
		i++;
		delay(5);
	}
}
void lcd_datanum(unsigned int data1)
{
	int k=0,p,x;
	while(data1!=0)
	{
		a[k]=data1%10;
		k++;
		data1=data1/10;
	}
	k--;
	for(p=k;p>=0;p--)
	{
		x=a[p]+48;
		lcd_display(x);
	}
}
void bcd_conv(unsigned char num)
{
	unsigned char x,y;
	x= num & 0xf0;
	x=x>>4;
	x=x|0x30;
	y= num & 0x0f;
	y=y|0x30;
	lcd_data(x);
	lcd_data(y);
}
void lcd_init(void)
{
	lcd_cmd(0x28);
	lcd_cmd(0x01);
	lcd_cmd(0x0c);
	lcd_cmd(0x80);
}