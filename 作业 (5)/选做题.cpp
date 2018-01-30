/*
�����ܣ������Ѽ�¼����
           ������Ѷ�
           �ܶ�
           500����������
           300��������������
           ���浽�ļ�
˵�����Ĵ��뻹��������дһ�������Ծ�����д��
Copyright XuTianyi��2017.12.21
*/

#include <iostream>
#include <fstream>
#include "cPublicTY.h"
using namespace std;
float dailySpend[32]={0};
void arrayInput(float *a,int len) //��������
{
  system("cls");
  cout<<"�밴˳������ÿ������Ѷ�������31�죬��ǰ����������-1"<<'\n';
  for (size_t i = 0; i < len; i++)
  {
    cin>>a[i];
    if(a[i]==-1) break;
  }
}

float arrayMaxDataF(float *a,int len)
{
  float max;
  max=a[0];
  for (size_t i = 0; i < len; i++)
  {
    if(max<a[i]) max=a[i];
  }
  return max;
}

int arrayMaxData(int *a,int len)
{
  int max;
  max=a[0];
  for (size_t i = 0; i < len; i++)
  {
    if(max<a[i]) max=a[i];
  }
  return max;
}

int dataLen(float *a,int len) //������ݲ���31ʱ��������ʩ
{
  int datalen=0;
   for (size_t i = 0; i < len; i++)
   {
     if(a[i]==-1) break;
     datalen++;
   }
   return datalen;
}

float arraySum(float a[],int len) //��ʵ��������ͣ����غ�
{
  float sum=0;
  for (size_t i = 0; i < len; i++)
  {
    sum+=a[i];
  }
  return sum;
}
void bye()
{
  system("cls");
  cout<<"��лʹ�ã��ټ���";
  for (size_t i = 0; i < 5; i++)
  {
    Sleep(500);
    cout<<".";
  }
  cout<<'\n';
  exit(0);
}

int dataCheck(float a[],int len) //����������ݵ���ȷ��
{
  int check=0,choice=0;
  for (size_t i = 0; i < len; i++)
  {
    if(a[i]!=0&&a[i]!=-1) check++;
  }
  if(check==0)
  {
    cout<<"error:����ȫ��Ϊ 0";
    cout<<"\n1.������������\n2.�˳�����\n";
    cin>>choice;
    if(choice==1)
    {
      arrayInput(dailySpend,31);
    }
    if(choice==2)
    {
      bye();
    }
  }
  return check;
}

int dayCount(float *a, int len ,int *p) //����500����������������300������
{
  int count500=0;
  for (size_t i = 0 , j = 0; i < len; i++)
  {
    if(a[i]>=300) p[j]++;
    else j++;
    if(a[i]>=500) count500++;
  }
  return count500;
}

void saveToFile()
{
  int datalen_s;
  time_t tm;
  tm=time(NULL);
  datalen_s=dataLen(dailySpend,31);
  ofstream Savefile("data.txt");
  Savefile<<"****�ɳ��򱣴������****\n----------------------------\n";
  Savefile<<"*ԭʼ����\n";
  Savefile<<" ����\t���Ѷ�\t\n";
  for (size_t i = 0; i < 31; i++)
  {
    if(dailySpend[i]==-1) dailySpend[i]=0;
    Savefile<<" "<<i+1<<'\t'<<dailySpend[i]<<'\n';
  }
  Savefile<<"\n----------------------------\n";
  Savefile<<"*�����ܶ�Ϊ��"<<arraySum(dailySpend,datalen_s)<<'\n';
  Savefile<<"\n----------------------------\n";
  int dayNum[32]={0};
  for (size_t i = 0 , j = 0; i < datalen_s; i++)
  {
    if(arrayMaxDataF(dailySpend,31)==dailySpend[i])
    dayNum[j]=i+1;
    j++;
  }
  Savefile<<"*������Ѷ�Ϊ"<<arrayMaxDataF(dailySpend,31);
  Savefile<<"��";
  for (size_t i = 0; i < datalen_s; i++)
  {
    if(dayNum[i]!=0)
    Savefile<<" ��"<<dayNum[i]<<"��";
  }
  Savefile<<"\n\n----------------------------\n";
  int count300[31]={0};
  Savefile<<"*���Ѷ��500�����Ϲ���"<<dayCount(dailySpend,datalen_s,count300)<<"��\n";
  Savefile<<"*���Ѷ��300���������"<<arrayMaxData(count300,31)<<"��";
  Savefile<<"\n\n----------------------------\n";
  Savefile<<"@time "<<tm;
}

void menu()
{
  system("cls");
  cout<<"��ѡ��Ҫִ�еĹ���"<<'\n';
  cout<<"1.��������"<<'\n';
  cout<<"2.��������"<<'\n';
  cout<<"3.�������Ѷ�"<<'\n';
  cout<<"4.��ʾ������Ѷ�Ͷ�Ӧ����"<<'\n';
  cout<<"5.ͳ�����Ѷ��500�����ϵ�������������300�����ϵ��������"<<'\n';
  cout<<"6.�����ݱ������ļ�"<<'\n';
  cout<<"7.�˳�����"<<'\n';
}

int main(int argc, char const *argv[])
{
  int choice=1;
  while(1)
  {
    menu();
    cin>>choice;
    switch (choice)
    {
      case 1 : arrayInput(dailySpend,31); break; //��������
      case 2 : //�������ݿ�ʼ
      {
        float dailySpendSort[32]={0};
        if(dataCheck(dailySpend,31)!=0)
        {
          for (size_t i = 0; i < dataLen(dailySpend,31); i++)
          {
            dailySpendSort[i]=dailySpend[i];
          }
          system("cls");
          BubbleSort_FBf_l(dailySpendSort,dataLen(dailySpend,31));
          cout<<"�������н�����£�\n";
          cout<<"(�Ӵ�С)\n";
          for (size_t i = 0; i < dataLen(dailySpend,31); i++)
          {
            cout<<dailySpendSort[i]<<'\n';
          }
        }
        break;
      }  //�������ݽ���
      case 3 : //��������ܶʼ
      {
        system("cls");
        if(dataCheck(dailySpend,31)!=0)
        cout<<"�����ܶ�Ϊ��"<<arraySum(dailySpend,dataLen(dailySpend,31))<<'\n';
        break;
      }  //��������ܶ����
      case 4 :
      {
        system("cls");
        int dayNum[32]={0};
         for (size_t i = 0 , j = 0; i < dataLen(dailySpend,31); i++)
         {
           if(arrayMaxDataF(dailySpend,31)==dailySpend[i])
           dayNum[j]=i+1;
           j++;
         }
         cout<<"������Ѷ�Ϊ"<<arrayMaxDataF(dailySpend,31);
         cout<<"��";
         for (size_t i = 0; i < dataLen(dailySpend,31); i++)
         {
           if(dayNum[i]!=0)
           cout<<" ��"<<dayNum[i]<<"��";
         }
         cout<<'\n';
         break;
      }  //��ʾ������Ѷ����
      case 5 :
      { //ͳ�����Ѷ��500�����ϵ�����
        system("cls");
        if(dataCheck(dailySpend,31)!=0)
        {
          int count300[31]={0};
          cout<<"���Ѷ��500�����Ϲ���"<<dayCount(dailySpend,dataLen(dailySpend,31),count300)<<"��\n";
          cout<<"���Ѷ��300���������"<<arrayMaxData(count300,31)<<"��\n";
        }
        break;
      }
      case 6 :
      {
        system("cls");
        if(dataCheck(dailySpend,31)!=0)
        {
          cout<<"ע�⣺�ļ��������ڳ���Ŀ¼�� data.txt��������ͬ�ļ������Ḳ�ǣ��Ƿ����\n";
          cout<<"1.����\n2.ȡ��\n";
          int choice=2;
          cin>>choice;
          if(choice==2) break;
          cout<<"���ڱ��浽�ļ�\n";
          saveToFile();
          Sleep(300);
          cout<<"�������\n";
        }
        break;
      }
      case 7 : bye();
    }
    system("pause");
    system("cls");
  }
  return 0;
}
