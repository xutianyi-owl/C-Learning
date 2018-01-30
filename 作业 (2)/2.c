#include <stdio.h>
int main(int argc, char const *argv[]) {

  int a[7],max,min;
  printf("输入7个整数\n");
  /*输入数字*/
  for (size_t i = 0; i < 7; i++)
  {
    scanf("%d",&a[i] );
  }
  /*寻找最大最小的数字*/
  max=a[0];
  min=a[0];
  for (size_t i = 0; i < 7; i++)
  {
    if (a[i]>max)
    max=a[i];
    if (a[i]<min)
    min=a[i];
  }
  /*定位最大最小并交换位置*/
  int max_p,min_p;
  for (size_t i = 0; i < 7; i++)
  {
    if (a[i]==max)
    {
      max_p=i;
      a[i]=min;
    }
    if (a[i]==min&&i!=max_p)
    {
      min_p=i;
      a[i]=max;
    }
  }
  printf("最大的数是 %d ，是第 %d 个 \n最小的数是 %d ，是第 %d 个 \n交换后的数列是:\n",max,max_p+1,min,min_p+1);
  for (size_t i = 0; i < 7; i++)
  {
    printf("%6d",a[i]);
  }
  printf("\n");
  return 0;
}
