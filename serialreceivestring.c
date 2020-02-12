#include<reg52.h>
#define lcdp P0
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<=1275;j++);
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
void lcd_init(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0c);
	lcd_cmd(0x80);
}
void main()
{
	//unsigned char dta[100];
	unsigned char dta;
	//int i;
	SCON=0x50;
	TMOD=0x20;
	TH1=-3;
	TR1=1;
	RI=0;
	lcd_init();
	while(1)
	{
		while(RI==0);
		dta=SBUF;
		RI=0;
		//lcd_init();
		lcd_data(dta);
	}
}