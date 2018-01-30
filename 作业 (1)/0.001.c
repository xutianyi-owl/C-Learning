#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[]) {
  float s=0,n=1,plus,cpr;
  for(n=1;;n++)
  {
  cpr=(2*n+1)/(2*n*2*n);
  plus=pow(-1,(n-1))*cpr;
  s=s+plus;
  if(cpr<=0.001)
  break;
  }
  printf("s=%f\n",s);
  return 0;
}
