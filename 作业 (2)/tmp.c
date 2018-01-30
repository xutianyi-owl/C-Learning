#include<stdio.h>
#include<string.h>
int main()
{
    char a[80],m,n,i;
    gets(a);
    for(i=0;i!='\0';i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
        {
            m=a[i]+3;
            if(m>='Z')
                a[i]=m-26;
        }
        else if(a[i]>='a'&&a[i]<='z')
        {
            n=a[i]+3;
            if(n>='z')
                a[i]=n-26;
        }
        puts(a);

    }
    return 0;
}
