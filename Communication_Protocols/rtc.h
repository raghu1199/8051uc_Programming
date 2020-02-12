#include "i2c.h"
#define D_ID 0xD0
#define SEC_ADDR 0x00
#define DATE_ADDR 0x04
#define CONTROL_ADDR 0x07
typedef unsigned char uch;
void rtc_write(uch dat)
{
	i2c_write(dat);
	i2c_clock();
}
uch rtc_read()
{
	uch dat;
	dat=i2c_read();
	return dat;
}
void rtc_setTime(uch hh,uch mm,uch ss)
{
	i2c_start();
	rtc_write(D_ID);
	rtc_write(SEC_ADDR);
	rtc_write(ss);
	rtc_write(mm);
	rtc_write(hh);
	i2c_stop();
}
void rtc_setDate(unsigned char dd,unsigned char mm,unsigned char yy)
{
	i2c_start();
	rtc_write(D_ID);
	rtc_write(DATE_ADDR);
	rtc_write(dd);
	rtc_write(mm);
	rtc_write(yy);
	i2c_stop();
}
void rtc_init()
{
	i2c_start();
	rtc_write(D_ID);
	rtc_write(CONTROL_ADDR);
	rtc_write(0x00);
	i2c_stop();
}
void rtc_getTime(uch *hh,uch *mm,uch *ss)
{
	i2c_start();
	rtc_write(D_ID);
	rtc_write(SEC_ADDR);
	i2c_stop();
	i2c_start();
	rtc_write(0xD1);
	*ss=rtc_read();
	i2c_ack();
	*mm=rtc_read();
	i2c_ack();
	*hh=rtc_read();
	i2c_ack();
	i2c_stop();
}
void rtc_getDate(unsigned char *dd,unsigned char *mm,unsigned char *yy)
{
	i2c_start();
	rtc_write(D_ID);
	rtc_write(DATE_ADDR);
	i2c_stop();
	i2c_start();
	rtc_write(0xD1);
	*dd=rtc_read();
	i2c_ack();
	*mm=rtc_read();
	i2c_ack();
	*yy=rtc_read();
	i2c_ack();
	i2c_stop();
}