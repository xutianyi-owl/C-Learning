#include<stdio.h>
int main()
{
char a[80]="wel",b[80]="come";//‘§¡ÙŒª÷√
    int i,n=0;
    while(!a[n]=='\0')  n++;
    for(i=0;b[i]!='\0';i++)
        a[n+i]=b[i];
    printf("%s\n",a);
    return 0;
}
