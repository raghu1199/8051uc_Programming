#include<reg52.h>
sbit s=P1^0;
void delay(unsigned int i)
{
	unsigned int j,k;
	for(j=0;j<=i;j++)
		for(k=0;k<=1000;k++);
}
void main()
{
	unsigned char x=0x00;
	while(1)
	{
			if(s==0)
			{
				delay(100);
				x++;
				P0=~(x);
			}
			if(x>0x0ff)
				x=0x01;
	}
}