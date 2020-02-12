#include<reg52.h>
void delay(unsigned int i)
{
	unsigned int j,k;
	for(j=0;j<=i;j++)
		for(k=0;k<=1000;k++);
}
void main()
{
	while(1)
	{
		unsigned char i,x,y;
		x=0x01;
		y=0x80;
		for(i=0;i<8;i++)
		{
			P0=~(x+y);
			x=x<<1;
			y=y>>1;
			delay(5);
		}
	}
}