#include <stdio.h>
int main(int argc, char const *argv[]) {

  int a[7],max,min;
  printf("����7������\n");
  /*��������*/
  for (size_t i = 0; i < 7; i++)
  {
    scanf("%d",&a[i] );
  }
  /*Ѱ�������С������*/
  max=a[0];
  min=a[0];
  for (size_t i = 0; i < 7; i++)
  {
    if (a[i]>max)
    max=a[i];
    if (a[i]<min)
    min=a[i];
  }
  /*��λ�����С������λ��*/
  int max_p,min_p;
  for (size_t i = 0; i < 7; i++)
  {
    if (a[i]==max)
    {
      max_p=i;
      a[i]=min;
    }
    if (a[i]==min&&i!=max_p)
    {
      min_p=i;
      a[i]=max;
    }
  }
  printf("�������� %d ���ǵ� %d �� \n��С������ %d ���ǵ� %d �� \n�������������:\n",max,max_p+1,min,min_p+1);
  for (size_t i = 0; i < 7; i++)
  {
    printf("%6d",a[i]);
  }
  printf("\n");
  return 0;
}
