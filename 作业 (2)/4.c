#include <stdio.h>
int main(int argc, char const *argv[]) {
  char chr[80];
  int k;
  printf("������Ҫ���ܵ��ַ�����������80���ַ����Իس�������\n");
  gets(chr);
  printf("�������������\n");
  scanf("%d",&k);
  /*��ʼ����*/
  for (size_t i = 0; chr[i]!='\0'; i++)
  {
    if(chr[i]>='a'&&chr[i]<='z')
    {
      chr[i]=chr[i]+k;
      while (chr[i]>='z')
      {
        chr[i]=chr[i]-26;
        if(chr[i]>='z')
        continue;
      }
    }

    if(chr[i]>='A'&&chr[i]<='Z')
    {
      chr[i]=chr[i]+k;
      while (chr[i]>='Z')
      {
        chr[i]=chr[i]-26;
        if(chr[i]>='Z')
        continue;
      }
    }

  }
  /*������ܺ���ַ���*/
  printf("%s",chr);
  printf("\n���ܽ���\n");
  return 0;
}
