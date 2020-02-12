#include<reg52.h>
#define lcd P0
#define led P1
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

unsigned char a=0x01,b=0x00;
void msdelay(int itime)
{
	int i,j;
	for(i=0;i<itime;i++)
		for(j=0;j<1275;j++);
}
void lcd_cmd(unsigned char cmd)
{
	lcd=cmd;
	rs=0;
	rw=0;
	en=1;
	msdelay(5);
	en=0;
}
void lcd_data(unsigned char udata)
{
	lcd=udata;
	rs=1;
	rw=0;
	en=1;
	msdelay(5);
	en=0;
}
void lcd_init()
{
	lcd_cmd(0x01);
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x80);
}
void extr0() interrupt 0
{
	led=0xff;
	msdelay(100);
	led=0x00;
	msdelay(100);
}

void serial() interrupt 4
{
	unsigned char c;
	if(RI==1)
	{
		c=SBUF;
		lcd_data(c);
		msdelay(100);
		RI=0;
	}
}
void main()
{
	lcd_init();
	SCON=0x50;
	TMOD=0x20;
	TH1=-3;
	TR1=1;
	IE=0x91;
	RI=0;
	while(1)
	{
		b=~(a);
		led=b;
		a++;
		msdelay(100);
	}
}