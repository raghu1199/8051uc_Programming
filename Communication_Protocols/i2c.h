sbit SCL=P3^6;
sbit SDA=P3^7;
void delay(int itime)
{
	int i,j;
	for(i=0;i<itime;i++)
		for(j=0;j<1275;j++);
}
void i2c_clock()
{
	delay(1);
	SCL=1;
	delay(1);
	SCL=0;
}
void i2c_start()
{
	SCL=0;
	SDA=1;
	delay(1);
	SCL=1;
	delay(1);
	SDA=0;
	delay(1);
	SCL=0;
}
void i2c_stop()
{
	SCL=0;
	delay(1);
	SDA=0;
	delay(1);
	SCL=1;
	delay(1);
	SDA=1;
	
}
void i2c_write(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SDA=dat & 0x80;
		i2c_clock();
		dat=dat<<1;
	}
	SDA=1;
}
unsigned char i2c_read()
{
	unsigned char i,dat=0x00;
	SDA=1;
	for(i=0;i<8;i++)
	{
		delay(1);
		SCL=1;
		delay(1);
		dat=dat<<1;
		dat=dat|SDA;
		SCL=0;
	}
	return dat;
}
void i2c_ack()
{
	SDA=0;
	i2c_clock();
	SDA=1;
}
void i2c_nack()
{
	SDA=1;
	i2c_clock();
	SCL=1;
}