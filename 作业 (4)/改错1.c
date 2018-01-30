#include<stdio.h>
int main()
{   int  i,n=0;
    char str[80];
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
      if(str[i]>='0'&&str[i]<='9')
      {
        n=n*10+str[i]-48;
      }
    }
    printf("%d  %d\n",n,2*n);
   return 0;
}
