#include <stdio.h>
int main(int argc, char const *argv[]) {
  float a[10],sum=0,avr;
  for (size_t i = 0; i < 10; i++)
  {
    printf("������� %d ��ͬѧ�ĳɼ�\n",i+1 );
    scanf("%f",&a[i]);
    sum+=a[i];
  }
  avr=sum/10;
  printf("ƽ������ %f �֣�����ƽ���ֵģ�",avr);
  size_t j=0;
  for (size_t i = 0; i < 10; i++)
  {
    if (a[i]>avr)
    {
      j++;
      printf("%6.2f",a[i] );
    }
  }
  /*����޴���ƽ��ֵ����*/
  if (j==0)
  {
    printf("��\n");
  }
  else
  {
    /*������ʵûʲô�ã����ǿ��������*/
    printf("\n");
  }

  return 0;
}
