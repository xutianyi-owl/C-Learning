#include <stdio.h>
struct book
{     char  name[20];    //����
      float price;       //����
      int   number;      //����
      float money;       //���
};
float sum(struct book *a, int n)
{
    int  j;
    float s=0.0;
    for (j=0; j<n; j++)
    {
        a[j].money = a[j].price*a[j].number;
        s = s+a[j].money;
    }
    return s;
}
int  main()
{
    struct book b[5]={ {"����",12.5,10},{"Ӣ��",25.3,5},{"�����",27.5,6},
                {"����",28.6,5},{"����",36.2,4}};
    int  i;
    float amount, final;
    amount = sum(b,5);
    if (amount<100)
       final = amount;
    else if (amount<500)
       final = amount*0.9;
    else
       final = amount*0.8;
    printf("%12s%12s%12s%12s\n","����","����","����","���");
    for (i=0; i<5; i++ )
        printf("%12s%12.2f%12d%10.2f\n",
                b[i].name,b[i].price,b[i].number,b[i].money);
    printf("�������Ϊ%10.2f\n�ۿۺ���%10.2f\n",amount,final);
    return 0;
}
