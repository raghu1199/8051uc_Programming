#include<reg52.h>
void delay(unsigned int i)
{
	unsigned int j,k;
	for(j=0;j<=i;j++)
		for(k=0;k<=1000;k++);
}
sbit s=P1^0;
void main()
{
	unsigned char i,x=0,z=0x01;
	while(1)
	{
		if(s==0)
		{
			while(s==0);	
			i=z;
			P0=~(i);
			z=z<<1;
		}
	}
}