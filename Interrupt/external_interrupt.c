#include<reg52.h>
sbit sw=P2^0;
void msdelay(int itime)
{
	int i,j;
	for(i=0;i<itime;i++)
		for(j=0;j<1275;j++);
}
void extern0() interrupt 0
{
	P2=0x00;
	msdelay(50);
	P2=0xff;
	msdelay(50);
}
void main()
{
	IE=0x81;
	while(1)
	{
		sw=~sw;
		msdelay(50);
	}
}
