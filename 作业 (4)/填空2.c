#define M 3
#define N 4
#include <stdio.h>
void main()
{
    int max,i,j,r,c;
    int a[M][N]={{123,94,-10,218},{3,9,10,-83},{45,16,44,-99}};
    max=a[0][0];
    for(i=0;i<M;i++)
    for(j=0;j<N;j++)
    if(a[i][j]>max)
    {
      max=a[i][j];
      r=i;
      c=j;
    }
    printf("max=%d ,row=%d,colum=%d\n",max,r,c);
}
