#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  int num;
  printf("����������ĸ���\n");
  scanf("%d",&num);
  printf("����������ÿ������\n");
  getchar();
  char Passwd[num][80];
  for (size_t i = 0; i < num; i++)
  {
    gets(Passwd[i]);
  }
  printf("��������£�\n");
int chr_num,Cchr_num,spe_num,num_num,check; //Сд��ĸ����д��ĸ���������,���֣�������
  for (size_t i = 0; i < num; i++)
  {
    /*��鳤��*/
    if (strlen(Passwd[i])<6)
    {
      printf("Not Safe\n");
    }
    else if (strlen(Passwd[i])>20)
    {
      printf("error (code 1:password too long)\n");
    }
    else
    {
      /*��ʼ������*/
      chr_num=0;
      Cchr_num=0;
      spe_num=0;
      num_num=0;
      check=0;
      /*�����ַ�����*/
      for (size_t j = 0; Passwd[i][j]!='\0'; j++)
      {
        if (Passwd[i][j]>='a'&&Passwd[i][j]<='z') chr_num++;
        else if (Passwd[i][j]>='A'&&Passwd[i][j]<='Z') Cchr_num++;
        else if (Passwd[i][j]>='0'&&Passwd[i][j]<='9') num_num++;
        else spe_num++;
      }
      /*�ж���������*/
      if(chr_num!=0) check++;
      if(Cchr_num!=0) check++;
      if(num_num!=0) check++;
      if(spe_num!=0) check++;
      if(check==1) printf("Not Safe\n");
      else if (check==2) printf("Medium Safe\n");
      else if (check>=3) printf("Safe\n");
      else printf("error (unknown)\n");
    }
  }

  return 0;
}
