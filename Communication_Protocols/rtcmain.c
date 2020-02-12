#include<reg52.h>
#include "rtc.h"
#include "lcd.h"
void main()
{
	uch sec,min,hour,day=0x00,month=0x00,year=0x00;
	lcd_init();
	rtc_init();
	rtc_setTime(0x12,0x58,0x50);
	rtc_setDate(0x20,0x12,0x19);
	
	while(1)
	{
		
		lcd_cmd(0x80);
		rtc_getDate(&day,&month,&year);
		lcd_displayrtcDate(day,month,year);
		
		msdelay(2);
		lcd_cmd(0xc0);
		rtc_getTime(&hour,&min,&sec);
		lcd_displayrtcTime(hour,min,sec);
		
	//	
	//	lcd_string("TIME: ");

		
	//	lcd_string("DATE: ");
		
	}
}