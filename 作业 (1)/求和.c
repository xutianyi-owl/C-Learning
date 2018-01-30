#include <stdio.h>
int main(int argc, char const *argv[]) {
  float s,plus,plus2;
  int n=20,i,j;
  for(i=1;i<=20;i++)
  {
    for(j=n;j>0;j--)
    {
      plus=j*10+0.5;
      plus2=plus2+plus;
      printf("2 %f\n",plus2);
      printf("1 %f\n",plus);

    }
    n--;
    s=s+plus2;
  }
  s=s+20;
  printf("%f",s);
  return 0;
}
