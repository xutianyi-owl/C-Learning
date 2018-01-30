#include <stdio.h>
int main()
{
    int i,m,n,count=0;
    for(i=1;i<=10000;++i)
    {
        n=0;
        for(m=1;m<i;++m)

            if(i%m==0)
               n+=m;
        if(n==i)
        {
            printf("%5d=%d",i,1);
            for(m=2;m<i;++m)
                if(i%m==0) printf("+%d",m);
                        printf("\n");
                        count++;
        }

    }

printf("\n共有：%d个完全数。\n",count);
return 0;
}
