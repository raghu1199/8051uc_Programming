#include<reg52.h>
sbit s=P1^0;
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<=1275;j++);
}
void main()
{
	int i=0;
	unsigned char a[]="HYY ";
	unsigned char b[]="HELLO ";
	SCON=0x50;
	TMOD=0x20;
	TH1=-3;
	TR1=1;
	while(1)
	{
		if(s==0)
		{
			for(i=0;a[i]!='\0';i++)
			{
				SBUF=a[i];
				while(TI==0);
				TI=0;
				delay(50);
			}
		}
		else
		{
			for(i=0;b[i]!='\0';i++)
			{
				SBUF=b[i];
				while(TI==0);
				TI=0;
				delay(50);
			}
		}
	}
}