#include<reg52.h>
sbit R0=P2^0;
sbit R1=P2^1;
sbit R2=P2^2;
sbit R3=P2^3;
sbit C0=P2^4;
sbit C1=P2^5;
sbit C2=P2^6;
sbit C3=P2^7;
sfr data_port1=0x80;
sfr data_port0=0x90;
void delay(int x)
{
	int i,j;
	for(i=0;i<=1275;i++)
		for(j=0;j<=x;j++);
}
void colfinder0()
{
	R0=R1=R2=R3=0;
	C0=C1=C2=C3=1;
	if(C0==0)
	{
		data_port0=0xC0;
		data_port1=0xC0;
	}
	if(C1==0)
	{
		data_port0=0xF9;
		data_port1=0xC0;
	}
	if(C2==0)
	{
		data_port0=0xA4;
		data_port1=0xC0;
	}
	if(C3==0)
	{
		data_port0=0xB0;
		data_port1=0xC0;
	}
}
void colfinder1()
{
	R0=R1=R2=R3=0;
	C0=C1=C2=C3=1;
	if(C0==0)
	{
		data_port0=0x99;
		data_port1=0xC0;
	}
	if(C1==0)
	{
		data_port0=0x92;
		data_port1=0xC0;
	}
	if(C2==0)
	{
		data_port0=0x82;
		data_port1=0xC0;
	}
	if(C3==0)
	{
		data_port0=0xF8;
		data_port1=0xC0;
	}
}
void colfinder2()
{
	R0=R1=R2=R3=0;
	C0=C1=C2=C3=1;
	if(C0==0)
	{
		data_port0=0x80;
		data_port1=0xC0;
	}
	if(C1==0)
	{
		data_port0=0x90;
		data_port1=0xC0;
	}
	if(C2==0)
	{
		data_port0=0xC0;
		data_port1=0xF9;
	}
	if(C3==0)
	{
		data_port0=0xF9;
		data_port1=0xF9;
	}
}
void colfinder3()
{
	R0=R1=R2=R3=0;
	C0=C1=C2=C3=1;
	if(C0==0)
	{
		data_port0=0xA4;
		data_port1=0xF9;
	}
	if(C1==0)
	{
		data_port0=0xB0;
		data_port1=0xF9;
	}
	if(C2==0)
	{
		data_port0=0x99;
		data_port1=0xF9;
	}
	if(C3==0)
	{
		data_port0=0x92;
		data_port1=0xF9;
	}
}
void main()
{
	while(1)
	{
		delay(20);
		R0=R1=R2=R3=1;
		C0=C1=C2=C3=0;
		if(R0==0)
			colfinder0();
		else if(R1==0)
			colfinder1();
		else if(R2==0)
			colfinder2();
		else if(R3==0)
			colfinder3();
	}
}