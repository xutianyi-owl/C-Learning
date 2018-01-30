#include <stdio.h>
int main(void)
{
    int  speed,limit; //speed:车速,limit:限速
    int  exceed;
    printf("请输入车辆行驶速度、高速公路的限速:");
    scanf("%d %d",&speed, &limit);
    exceed = 100*(speed-limit)/limit;
    if (exceed<10)
        printf("OK\n");
    else if (exceed>=10&&exceed<20)
        printf("超速%d%%.扣3分. 罚款200元\n",exceed );
    else if (exceed>=20&&exceed<50)
        printf("超速%d%%.扣6分. 罚款200元\n",exceed );
    else
        printf("超速%d%%.扣12分. 罚款2000元\n",exceed );
    return 0;
}
