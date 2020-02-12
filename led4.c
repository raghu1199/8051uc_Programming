#include<reg52.h>
sbit s=P1^0;
//sbit led=P0^0;
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
		//unsigned char s;
		if(s==0)
			P0=0x00;
		else
			P0=0xff;
	}
}