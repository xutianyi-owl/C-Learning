#include <stdio.h>
#include <string.h>

int check_firstNum(char *a) //����һ���ַ��ǲ������֣������ַ��� 0�����Ƿ��� 1
{
  if (a[0]>='0'&&a[0]<='9')
  return 0;
  else
  return 1;
}

int check_specchar(char *a) //����Ƿ���ڷǷ������ַ������ڷ���λ��
{
  int posi;
  int len=strlen(a);
  for (size_t i = 0; i < len; i++)
  {
    if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'||a[i]=='_'||a[i]>='0'&&a[i]<='9')
    {
      posi=0;
    }
    else
    {
      posi=i;
      break;
    }
  }
  return posi;
}

int main(int argc, char const *argv[])
{
  char strToCheck[100];
  printf("������Ҫ���ı�ʶ��\n");
  gets(strToCheck);
  if(check_firstNum(strToCheck)==0)
  {
    printf("error���� 1 ���ַ�����Ϊ ����:%c\n",strToCheck[0]);
  }
  else if(check_specchar(strToCheck)!=0)
  {
    printf("error: ��%d���ַ�Ϊ�Ƿ������ַ�:%c\n",check_specchar(strToCheck)+1,strToCheck[check_specchar(strToCheck)]);
  }
  else
  {
    printf("Yes\n");
  }
  return 0;
}
