#include<reg52.h>
sbit IN1=P0^0;
sbit IN2=P0^1;
sbit CLKW_SW=P1^0;
sbit ACLK_SW=P1^1;
sbit PWM_80=P1^2;
sbit PWM_20=P1^3;
void TIMER_1mS()
{
	TH0=0xFC;
	TL0=0x66;						//1mS Timer Delay
	TR0=1;
	while(TF0==0);
	TF0=0;
	TR0=0;
}
void main()
{
	unsigned char i,delaytime_ms=0;
	P0=0x00;			//OUTPUT PORT
	P1=0xFF;			//INPUT PORT
	
	TMOD=0x01;
	while(1)
	{
		if(CLKW_SW==0)
		{
			IN1=1;
			IN2=0;
		}
		else if(ACLK_SW==0)
		{
			IN1=0;
			IN2=1;
		}
		else if(PWM_80==0)
		{
			IN2=0;
			delaytime_ms=60;				//800ms High Time
			IN1=1;
			
			for(i=0; i<=delaytime_ms; i++)
				TIMER_1mS();	
			
			delaytime_ms=40;				//200ms Low Time
			IN1=0;
			
			for(i=0; i<=delaytime_ms; i++)
				TIMER_1mS();
			
		}
		else if(PWM_20==0)
		{
			IN2=0;
			delaytime_ms=800;				//200ms High Time
			IN1=1;
			
			for(i=0; i<=delaytime_ms; i++)
				TIMER_1mS();	
			
			delaytime_ms=1200;				//800ms Low Time
			IN1=0;
			
			for(i=0; i<=delaytime_ms; i++)
				TIMER_1mS();
			
		}
		else
		{
			IN1=1;
			IN2=1;
		}
	}
}