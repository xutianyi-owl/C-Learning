#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[]) {
  srand( (unsigned)time( NULL ) );
  int a,b,c,d,test1,test2;
for(;;)
{
  a=rand()%10;
  b=rand()%10;
  c=rand()%10;
  d=rand()%10;
test1=(102+a*10)*(30+b);
test2=(c*1000)+750+d;
  if(test1==test2)
  {
    printf("%d %d %d %d\n",a,b,c,d);
    //break;
  }

  else
  continue;
}

  return 0;
}
