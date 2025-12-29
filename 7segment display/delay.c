#include<lpc21xx.H>
#include"delay.h"
typedef unsigned int u32;

void delay_second(u32 second)
{
T0PR=15000000-1;
T0TCR=0x01;
while(T0TC<second);
T0TCR=0x03;
T0TCR=0x00;
}
void delay_ms(u32 ms)
{
T0PR=15000-1;
T0TCR=0x01;
while(T0TC<ms);
T0TCR=0x03;
T0TCR=0x00;
}
void delay_us(u32 us)
{
T0PR=15-1;
T0TCR=0x01;
while(T0TC<us);
T0TCR=0x03;
T0TCR=0x00;
}

