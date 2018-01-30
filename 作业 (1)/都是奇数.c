#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[]) {
  int n;
  srand( (unsigned)time( NULL ) );
  scanf("%d",&n);
  int a[n],sum=0,i;
  for(i=0;i<n;i++)
  {
    a[i]=rand()%101;
  }
  for(i=0;i<n;i++)
  {
    if(i%2!=0&&a[i]%2!=0)
    {
      printf("%d %d\n",a[i],i);
      sum++;
      break;
    }
    else
    {
      continue;
    }
  }
  printf("sum=%d\n",sum );
  return 0;
}
