#include <stdio.h>
int main(void)
{
    int  speed,limit; //speed:����,limit:����
    int  exceed;
    printf("�����복����ʻ�ٶȡ����ٹ�·������:");
    scanf("%d %d",&speed, &limit);
    exceed = 100*(speed-limit)/limit;
    if (exceed<10)
        printf("OK\n");
    else if (exceed>=10&&exceed<20)
        printf("����%d%%.��3��. ����200Ԫ\n",exceed );
    else if (exceed>=20&&exceed<50)
        printf("����%d%%.��6��. ����200Ԫ\n",exceed );
    else
        printf("����%d%%.��12��. ����2000Ԫ\n",exceed );
    return 0;
}
