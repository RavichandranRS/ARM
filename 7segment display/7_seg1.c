#include<LPC21xx.h>
#include"delay.h"
#define seg_d 0xff
#define seg_1 1<<8
#define seg_2 1<<9
#define seg_3 1<<10
#define seg_4 1<<11
typedef unsigned char u8;
u8 seg_lut[]={0xc0,0xf9,0xA4,0xB0,0x99,0x92,0x82,0xf8,0x80,0x98};
void float_display(float);
void int_display(int);
int dp1=0,dp2=0,dp3=0,dp4=0;
					 
int main()
{
 while(1)
 {
  	float_display(1234);
 }
}

void float_display(float n)
{
 int temp;
 temp =n;
 if((n>=0)&&(n<=10))
 {
  dp1=0x80;
  temp=n*1000;
 }
  else if((n>=10)&&(n<=100))
 {
  dp2=0x80;
  temp=n*100;
 }
  else if((n>=100)&&(n<=1000))
 {
  dp3=0x80;
  temp=n*10;
 }
  else 
 {
  dp4=0x80;
  temp=n;
 }

  int_display(temp);

}
void int_display(int n)
{
 IODIR0=seg_d;
 IOSET0=seg_lut[(n/1000)];
 IOCLR0=seg_1;
 delay_ms(5);
 IOSET0=seg_1;

 IODIR0=seg_d;
 IOSET0=seg_lut[(n/100)%10];
 IOCLR0=seg_2;
 delay_ms(5);
 IOSET0=seg_2;

  IODIR0=seg_d;
 IOSET0=seg_lut[(n/10)%10];
 IOCLR0=seg_3;
 delay_ms(5);
 IOSET0=seg_3;

   IODIR0=seg_d;
 IOSET0=seg_lut[n%10];
 IOCLR0=seg_4;
 delay_ms(5);
 IOSET0=seg_4;

}
