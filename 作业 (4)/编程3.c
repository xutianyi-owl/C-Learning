/*
If the texts show wrong , please change code type to "GBK"
������û���Ϣ����� users.db�ļ��У�չʾ��Ϣ����� cont.db�ļ��У����������ı��༭���򿪡�
��Ҫ�Զ���ͷ�ļ�"CPublicTY.h"
�û��ļ������������û�������һ��Ϊ��Ӧ������
ȫ���ļ��ı����ʽ��ΪGBK
���õ��˻���Ϣ����(�û��� ����)��
admin     37efac520a78beb36e9cbcfcdf6b0aa8  ������Ա��
xutianyi  94704b5271a40b0796aaa78f24a8414b   ����ͨ�û���
user2     75ceccec147c8b11e81c7464af2246c2
user3     28e5075a6608dce291b2ec92e0e95ea4
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "CPublicTY.h"
FILE *fp_users=NULL;
FILE *fp_cont=NULL;
//�ҵ��Զ��延ӭ����
void welcom()   //��װ����һ�����˳����ļ�����ȥ
{

    system("mode con cols=100 lines=30");
    int i = 0,j=0;
    for (j=0;j<30;j++)
    {
      if (j==12)
      {
        for(i=0;i<45;i++)
        printf(" ");
        printf("���ڼ���..");
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
              if(fp_users==NULL)             //�ж��ļ��򿪵���ȷ��
              {
               MessageBox(NULL,"File Missing (users.db)","error",0);
               exit(0);
              }
            }
            if(i==50)
            {
              fp_cont=fopen("cont.db","r");
              if(fp_cont==NULL)             //�ж��ļ��򿪵���ȷ��
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
    MessageBox(NULL,"��ӭ���뱾ϵͳ","�������",0);
    system("cls");
}
void user_interface()
{
  char chos_titl[4][100],content[3][500];
  //չʾ����
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
  printf("��������Ҫ�鿴������\n");
  int choice;
  scanf("%d",&choice);
  system("cls");
  puts(chos_titl[choice]);
  printf("%s\n",content[choice-1] );
  printf("\n");
}
void admin_interface()
{
  //printf("you are a admin\n");��
  fclose(fp_users);
  fclose(fp_cont);
  fp_users=fopen("users.db","r+");
  fp_cont=fopen("cont.db","r+");
  printf("��ѡ�������\n2.�鿴չʾ����\n3.�༭չʾ����\n");
  int do_ch;
  char chos_titl[4][100],content[3][500];
  scanf("%d",&do_ch);
  if(do_ch==1);
  if(do_ch==2)
  {
    //չʾ����
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
    //�༭����
    system("cls");
    printf("������չʾ���\n");
    scanf("%s", chos_titl[0]);
    int len=0;
    len=strlen(chos_titl[0]);
    chos_titl[0][len]='\n';
    chos_titl[0][len+1]='\0';
    fputs(chos_titl[0],fp_cont);
    for (size_t i = 1; i < 4; i++)
    {
      printf("������� %d ����Ʒ����\n",i);
      scanf("%s", chos_titl[i]);
      int len=0;
      len=strlen(chos_titl[i]);
      chos_titl[i][len]='\n';
      chos_titl[i][len+1]='\0';
      fputs(chos_titl[i],fp_cont);
    }
    for (size_t i = 0; i < 3; i++)
    {
      printf("������� %d ����Ʒ����\n",i+1);
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
  //��Զ���û�����Ĵ���
  user_count=(FILE_LINE(fp_users))*2;
  char user[user_count][81];
  fp_users=fopen("users.db","r");
  for (size_t i = 0; i < user_count; i++)
  {
    fgets(user[i],80,fp_users);
    user[i][strlen(user[i])-1]='\0';
  }
  //��֤�û���������
  int flag=0,pos=0;
  char user_name[81],user_pass[81];
  //����������ģʽ�����
  char system_admin[]="admin";
  char admin_passwd[]="37efac520a78beb36e9cbcfcdf6b0aa8";
  printf("�������û�����\n");
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
    if(flag!=1) printf("��������������\n");
    if(flag==1) break;
  }
  printf("���������룺\n");
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
    printf("��������������\n");
    if(atps>2)
    {
      printf("�û�����ʧ�ܣ������˳�\n");
      exit(0);
    }
  }
  return 0;
}
