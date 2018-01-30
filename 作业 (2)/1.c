#include <stdio.h>
int main(int argc, char const *argv[]) {
  float a[10],sum=0,avr;
  for (size_t i = 0; i < 10; i++)
  {
    printf("请输入第 %d 名同学的成绩\n",i+1 );
    scanf("%f",&a[i]);
    sum+=a[i];
  }
  avr=sum/10;
  printf("平均分是 %f 分，超过平均分的：",avr);
  size_t j=0;
  for (size_t i = 0; i < 10; i++)
  {
    if (a[i]>avr)
    {
      j++;
      printf("%6.2f",a[i] );
    }
  }
  /*解决无大于平均值问题*/
  if (j==0)
  {
    printf("无\n");
  }
  else
  {
    /*这里其实没什么用，就是看起来舒服*/
    printf("\n");
  }

  return 0;
}
