#include<reg52.h>
void send(unsigned char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		SBUF=a[i];
		while(TI==0);
		TI=0;
	}
}
void main()
{
	unsigned char a[]="Rahul";
	SCON=0x50;
	TMOD=0x20;
	TH1=-3;
	TR1=1;
	send(a);
	while(1);
}