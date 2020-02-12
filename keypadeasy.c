#include<reg52.h>
#include "lcd4bit.h"
sbit R0=P0^0;
sbit R1=P0^1;
sbit R2=P0^2;
sbit R3=P0^3;
sbit C0=P0^4;
sbit C1=P0^5;
sbit C2=P0^6;
sbit C3=P0^7;
void row_finder0()
{
	R0=R1=R2=R3=1;
	C0=C1=C2=C3=0;
	if(R0==0)
		lcd_display('1');
	if(R1==0)
		lcd_display('4');
	if(R2==0)
		lcd_display('7');
	if(R3==0)
		lcd_display('*');
}
void row_finder1()
{
	R0=R1=R2=R3=1;
	C0=C1=C2=C3=0;
	if(R0==0)
		lcd_display('2');
	if(R1==0)
		lcd_display('5');
	if(R2==0)
		lcd_display('8');
	if(R3==0)
		lcd_display('0');
}
void row_finder2()
{
	R0=R1=R2=R3=1;
	C0=C1=C2=C3=0;
	if(R0==0)
		lcd_display('3');
	if(R1==0)
		lcd_display('6');
	if(R2==0)
		lcd_display('9');
	if(R3==0)
		lcd_display('#');
}
void row_finder3()
{
	R0=R1=R2=R3=1;
	C0=C1=C2=C3=0;
	if(R0==0)
		lcd_display('A');
	if(R1==0)
		lcd_display('B');
	if(R2==0)
		lcd_display('C');
	if(R3==0)
		lcd_display('D');
}
void main()
{
	lcd_init();
	while(1)
	{
		delay(20);
		R0=R1=R2=R3=0;
		C0=C1=C2=C3=1;
		if(C0==0)
			row_finder0();
		else if(C1==0)
			row_finder1();
		else if(C2==0)
			row_finder2();
		else if(C3==0)
			row_finder3();
	}
}