#include<reg52.h>
#define lcd P0
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
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
void lcd_init(void)
{
	lcd_cmd(0x01);
	lcd_cmd(0x02);
	lcd_cmd(0x0c);
	lcd_cmd(0x38);
	lcd_cmd(0x80);
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
void lcd_string(unsigned char a[])
{
	int i=0;
	while(a[i]!='\0')
	{	
		lcd_data(a[i]);
		i++;
		msdelay(5);
	}
}
void bcd_conv(uch num)
{
	uch x,y;
	x=num & 0xf0;
	x=x>>4;
	x=x|0x30;
	y=num & 0x0f;
	y=y|0x30;
	lcd_data(x);
	lcd_data(y);
}
void lcd_displayrtcTime(uch hh,uch mm,uch ss)
{
	bcd_conv(hh);
	lcd_data(':');
	bcd_conv(mm);
	lcd_data(':');
	bcd_conv(ss);
}
void lcd_displayrtcDate(uch dd,uch mm,uch yy)
{
	bcd_conv(dd);
	lcd_data('/');
	bcd_conv(mm);
	lcd_data('/');
	bcd_conv(yy);
}