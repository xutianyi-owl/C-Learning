#include <stdio.h>
#include "CPublicTY.h"
int main(int argc, char const *argv[])
{
  srand((unsigned int)(time(NULL)));
  int rad,i,j;
  int num[51],all[51];
  for (i=0;i<50;i++)
  {
    all[i]=Rand_S(10,99);
  }
  int sum=0;
  float avr;
  for (i = 0; i < 50 ; i++)
  {
    sum=sum+all[i];
  }
  avr=((float)sum)/50.0;
  for (i = 0 ,j = 0; i < 50; i++)
  {
    if(all[i]>avr&&all[i]%5==0&&all[i]%10!=0||all[i]/50==0&&all[i]>=50)
    {
      num[j]=all[i];
      j++;
    }
  }
  num[j]='\0';
  BubbleSort_FB_l(num,strlen(num));
  for (size_t i = 0; num[i]!='\0'; i++)
  {
    printf("%d ",num[i]);
  }
  return 0;
}
