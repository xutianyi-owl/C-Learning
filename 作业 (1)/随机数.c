#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
 {
  srand( (unsigned)time( NULL ) );
  int count,num,line=0,r=0;
  for(count=0;count<30;)
  {
    num=rand()%1001;
    r++;
    if(num%2==0)
    {
      printf("%d",num);
      count++;
      line++;
      if(line%8==0)
      {
        printf("\n");
      }
      else
      {
        printf(" ");
      }
    }
    else
    {
      continue;
    }


  }
  printf("\n Rand=%d\n",r);
  return 0;
}
