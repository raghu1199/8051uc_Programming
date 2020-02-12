#include<reg52.h>
sfr lcdp=0x80;
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
int a[10];
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
void lcd_display(unsigned char data1)
{
	lcdp=data1;
	rs=1;
	rw=0;
	en=1;
	delay(5);
	en=0;
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
void main()
{
	lcd_init();
	lcd_datanum(65535);
	while(1);
} 