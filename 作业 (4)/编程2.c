#include <stdio.h>
int main(int argc, char const *argv[]) {
//��ʼ����Ʊ
  int num_1,num_2,num_3,num_4,num_5;
  num_1=0;
  num_2=0;
  num_3=0;
  num_4=0;
  num_5=0;
//��ʼ��Ʊ
  printf("��ʼ��¼ѡƱ...\n������ѡƱ��ÿ����һ�����»س������� -1 ����\n");

  for(;;)
  {
    int n;
    scanf("%d",&n);
    if(n==1) num_1++;
    else if(n==2) num_2++;
    else if(n==3) num_3++;
    else if(n==4) num_4++;
    else if(n==5) num_5++;
    else if(n==-1) break;
    else printf("error\n");
  }

  printf("��Ʊ�������\n");
  printf("��ѡ��\t1\t2\t3\t4\t5\n");
  printf("��Ʊ��\t%d\t%d\t%d\t%d\t%d\n",num_1,num_2,num_3,num_4,num_5);
  return 0;
}
