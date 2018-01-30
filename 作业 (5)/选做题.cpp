/*
程序功能：月消费记录处理：
           最大消费额
           总额
           500或以上天数
           300或以上连续天数
           保存到文件
说明：改代码还不如重新写一个，所以就重新写了
Copyright XuTianyi，2017.12.21
*/

#include <iostream>
#include <fstream>
#include "cPublicTY.h"
using namespace std;
float dailySpend[32]={0};
void arrayInput(float *a,int len) //输入数据
{
  system("cls");
  cout<<"请按顺序输入每天的消费额，最多输入31天，提前结束请输入-1"<<'\n';
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

int dataLen(float *a,int len) //针对数据不足31时的修正措施
{
  int datalen=0;
   for (size_t i = 0; i < len; i++)
   {
     if(a[i]==-1) break;
     datalen++;
   }
   return datalen;
}

float arraySum(float a[],int len) //对实型数组求和，返回和
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
  cout<<"感谢使用，再见！";
  for (size_t i = 0; i < 5; i++)
  {
    Sleep(500);
    cout<<".";
  }
  cout<<'\n';
  exit(0);
}

int dataCheck(float a[],int len) //检测输入数据的正确性
{
  int check=0,choice=0;
  for (size_t i = 0; i < len; i++)
  {
    if(a[i]!=0&&a[i]!=-1) check++;
  }
  if(check==0)
  {
    cout<<"error:数据全部为 0";
    cout<<"\n1.重新输入数据\n2.退出程序\n";
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

int dayCount(float *a, int len ,int *p) //超过500的天数，连续超过300的天数
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
  Savefile<<"****由程序保存的数据****\n----------------------------\n";
  Savefile<<"*原始数据\n";
  Savefile<<" 天数\t消费额\t\n";
  for (size_t i = 0; i < 31; i++)
  {
    if(dailySpend[i]==-1) dailySpend[i]=0;
    Savefile<<" "<<i+1<<'\t'<<dailySpend[i]<<'\n';
  }
  Savefile<<"\n----------------------------\n";
  Savefile<<"*消费总额为："<<arraySum(dailySpend,datalen_s)<<'\n';
  Savefile<<"\n----------------------------\n";
  int dayNum[32]={0};
  for (size_t i = 0 , j = 0; i < datalen_s; i++)
  {
    if(arrayMaxDataF(dailySpend,31)==dailySpend[i])
    dayNum[j]=i+1;
    j++;
  }
  Savefile<<"*最大消费额为"<<arrayMaxDataF(dailySpend,31);
  Savefile<<"在";
  for (size_t i = 0; i < datalen_s; i++)
  {
    if(dayNum[i]!=0)
    Savefile<<" 第"<<dayNum[i]<<"天";
  }
  Savefile<<"\n\n----------------------------\n";
  int count300[31]={0};
  Savefile<<"*消费额达500及以上共有"<<dayCount(dailySpend,datalen_s,count300)<<"天\n";
  Savefile<<"*消费额达300连续最多有"<<arrayMaxData(count300,31)<<"天";
  Savefile<<"\n\n----------------------------\n";
  Savefile<<"@time "<<tm;
}

void menu()
{
  system("cls");
  cout<<"请选择要执行的功能"<<'\n';
  cout<<"1.输入数据"<<'\n';
  cout<<"2.排列数据"<<'\n';
  cout<<"3.求总消费额"<<'\n';
  cout<<"4.显示最大消费额和对应日期"<<'\n';
  cout<<"5.统计消费额达500及以上的天数、连续达300及以上的最多天数"<<'\n';
  cout<<"6.将数据保存至文件"<<'\n';
  cout<<"7.退出程序"<<'\n';
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
      case 1 : arrayInput(dailySpend,31); break; //输入数据
      case 2 : //排列数据开始
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
          cout<<"数据排列结果如下：\n";
          cout<<"(从大到小)\n";
          for (size_t i = 0; i < dataLen(dailySpend,31); i++)
          {
            cout<<dailySpendSort[i]<<'\n';
          }
        }
        break;
      }  //排列数据结束
      case 3 : //输出消费总额开始
      {
        system("cls");
        if(dataCheck(dailySpend,31)!=0)
        cout<<"消费总额为："<<arraySum(dailySpend,dataLen(dailySpend,31))<<'\n';
        break;
      }  //输出消费总额结束
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
         cout<<"最大消费额为"<<arrayMaxDataF(dailySpend,31);
         cout<<"在";
         for (size_t i = 0; i < dataLen(dailySpend,31); i++)
         {
           if(dayNum[i]!=0)
           cout<<" 第"<<dayNum[i]<<"天";
         }
         cout<<'\n';
         break;
      }  //显示最大消费额结束
      case 5 :
      { //统计消费额达500及以上的天数
        system("cls");
        if(dataCheck(dailySpend,31)!=0)
        {
          int count300[31]={0};
          cout<<"消费额达500及以上共有"<<dayCount(dailySpend,dataLen(dailySpend,31),count300)<<"天\n";
          cout<<"消费额达300连续最多有"<<arrayMaxData(count300,31)<<"天\n";
        }
        break;
      }
      case 6 :
      {
        system("cls");
        if(dataCheck(dailySpend,31)!=0)
        {
          cout<<"注意：文件将保存在程序目录下 data.txt，如有相同文件名将会覆盖，是否继续\n";
          cout<<"1.继续\n2.取消\n";
          int choice=2;
          cin>>choice;
          if(choice==2) break;
          cout<<"正在保存到文件\n";
          saveToFile();
          Sleep(300);
          cout<<"保存完成\n";
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
