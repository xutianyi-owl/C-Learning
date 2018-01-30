/*
If the texts show wrong , please change code type to "GBK"
程序的用户信息存放在 users.db文件中，展示信息存放在 cont.db文件中，均可以用文本编辑器打开。
需要自定义头文件"CPublicTY.h"
用户文件中奇数行是用户名，下一行为对应的密码
全部文件的编码格式均为GBK
内置的账户信息如下(用户名 密码)：
admin     37efac520a78beb36e9cbcfcdf6b0aa8  【管理员】
xutianyi  94704b5271a40b0796aaa78f24a8414b   【普通用户】
user2     75ceccec147c8b11e81c7464af2246c2
user3     28e5075a6608dce291b2ec92e0e95ea4
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "CPublicTY.h"
FILE *fp_users=NULL;
FILE *fp_cont=NULL;
//我的自定义欢迎界面
void welcom()   //假装加载一会儿，顺便把文件导进去
{

    system("mode con cols=100 lines=30");
    int i = 0,j=0;
    for (j=0;j<30;j++)
    {
      if (j==12)
      {
        for(i=0;i<45;i++)
        printf(" ");
        printf("正在加载..");
        for(i=0;i<45;i++)
        printf(" ");
      }
      else if(j==15)
      {
        for (i = 1; i <= 100; ++i)
        {
            printf("-");
        }
        fflush(stdout);
        for (i = 1; i <= 100; ++i)
        {
            printf("\b");
        }
        for (i = 1; i <= 100; ++i)
        {
            printf(">");
            fflush(stdout);
            Sleep(15);
            if(i==20)
            {
              fp_users=fopen("users.db","r");
              if(fp_users==NULL)             //判断文件打开的正确性
              {
               MessageBox(NULL,"File Missing (users.db)","error",0);
               exit(0);
              }
            }
            if(i==50)
            {
              fp_cont=fopen("cont.db","r");
              if(fp_cont==NULL)             //判断文件打开的正确性
              {
               MessageBox(NULL,"File Missing (cont.db)","error",0);
               exit(0);
              }
            }
        }
      }
      else
      for (i = 0; i < 100; i++)
      {
        printf(" ");
      }
    }
    Sleep(100);
    MessageBox(NULL,"欢迎进入本系统","加载完成",0);
    system("cls");
}
void user_interface()
{
  char chos_titl[4][100],content[3][500];
  //展示数据
  system("cls");
  for (size_t i = 0; i < 4; i++)
  {
    fgets(chos_titl[i],100,fp_cont);
    chos_titl[i][strlen(chos_titl[i])-1]='\0';
    puts(chos_titl[i]);
  }
  for (size_t i = 0; i < 3; i++)
  {
    fgets(content[i],100,fp_cont);
    content[i][strlen(content[i])-1]='\0';
    //puts(content[i]);
  }
  printf("请输入想要查看的内容\n");
  int choice;
  scanf("%d",&choice);
  system("cls");
  puts(chos_titl[choice]);
  printf("%s\n",content[choice-1] );
  printf("\n");
}
void admin_interface()
{
  //printf("you are a admin\n");。
  fclose(fp_users);
  fclose(fp_cont);
  fp_users=fopen("users.db","r+");
  fp_cont=fopen("cont.db","r+");
  printf("请选择操作：\n2.查看展示数据\n3.编辑展示数据\n");
  int do_ch;
  char chos_titl[4][100],content[3][500];
  scanf("%d",&do_ch);
  if(do_ch==1);
  if(do_ch==2)
  {
    //展示数据
    system("cls");
    for (size_t i = 0; i < 3; i++)
    {
      fgets(chos_titl[i],100,fp_cont);
      chos_titl[i][strlen(chos_titl[i])-1]='\0';
      puts(chos_titl[i]);
    }
  }
  if(do_ch==3)
  {
    //编辑数据
    system("cls");
    printf("请输入展示类别：\n");
    scanf("%s", chos_titl[0]);
    int len=0;
    len=strlen(chos_titl[0]);
    chos_titl[0][len]='\n';
    chos_titl[0][len+1]='\0';
    fputs(chos_titl[0],fp_cont);
    for (size_t i = 1; i < 4; i++)
    {
      printf("请输入第 %d 种物品名称\n",i);
      scanf("%s", chos_titl[i]);
      int len=0;
      len=strlen(chos_titl[i]);
      chos_titl[i][len]='\n';
      chos_titl[i][len+1]='\0';
      fputs(chos_titl[i],fp_cont);
    }
    for (size_t i = 0; i < 3; i++)
    {
      printf("请输入第 %d 种物品描述\n",i+1);
      scanf("%s", content[i]);
      len=strlen(content[i]);
      content[i][len]='\n';
      content[i][len+1]='\0';
      fputs(content[i],fp_cont);
    }
    fclose(fp_cont);
  }
}
int main(int argc, char const *argv[])
{
  welcom();
  int user_count=1;
  //针对多个用户情况的处理
  user_count=(FILE_LINE(fp_users))*2;
  char user[user_count][81];
  fp_users=fopen("users.db","r");
  for (size_t i = 0; i < user_count; i++)
  {
    fgets(user[i],80,fp_users);
    user[i][strlen(user[i])-1]='\0';
  }
  //验证用户名和密码
  int flag=0,pos=0;
  char user_name[81],user_pass[81];
  //定义进入管理模式的入口
  char system_admin[]="admin";
  char admin_passwd[]="37efac520a78beb36e9cbcfcdf6b0aa8";
  printf("请输入用户名：\n");
  while (1)
  {
    gets(user_name);
    if(strcmp(user_name,system_admin)==0) break;
    for (size_t i = 0; i < user_count; i++)
    {
      if(strcmp(user_name,user[i])==0)
      {
        pos=i;
        flag=1;
        break;
      }
    }
    if(flag!=1) printf("错误，请重新输入\n");
    if(flag==1) break;
  }
  printf("请输入密码：\n");
  int atps=0;
  while (1)
  {
    gets(user_pass);
    if(strcmp(user_pass,admin_passwd)==0)
    {
      system("cls");
      admin_interface();
      break;
    }
    if(strcmp(user_pass,user[pos+1])==0)
    {
      system("cls");
      user_interface();
      break;
    }
    atps++;
    printf("错误，请重新输入\n");
    if(atps>2)
    {
      printf("用户鉴定失败，正在退出\n");
      exit(0);
    }
  }
  return 0;
}
