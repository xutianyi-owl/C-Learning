#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  int num;
  printf("请输入密码的个数\n");
  scanf("%d",&num);
  printf("请依次输入每个密码\n");
  getchar();
  char Passwd[num][80];
  for (size_t i = 0; i < num; i++)
  {
    gets(Passwd[i]);
  }
  printf("检查结果如下：\n");
int chr_num,Cchr_num,spe_num,num_num,check; //小写字母，大写字母，特殊符号,数字，检查变量
  for (size_t i = 0; i < num; i++)
  {
    /*检查长度*/
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
      /*初始化计数*/
      chr_num=0;
      Cchr_num=0;
      spe_num=0;
      num_num=0;
      check=0;
      /*计算字符个数*/
      for (size_t j = 0; Passwd[i][j]!='\0'; j++)
      {
        if (Passwd[i][j]>='a'&&Passwd[i][j]<='z') chr_num++;
        else if (Passwd[i][j]>='A'&&Passwd[i][j]<='Z') Cchr_num++;
        else if (Passwd[i][j]>='0'&&Passwd[i][j]<='9') num_num++;
        else spe_num++;
      }
      /*判断类型数量*/
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
