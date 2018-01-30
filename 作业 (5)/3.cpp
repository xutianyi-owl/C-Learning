#include <iostream>
#include "cPublicTY.h"
using namespace std;
int scoreByStudent[10][5];
int scoreBySubject[5][10];
void welcom()   //懒得重新写了，用上次的吧
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
double avr(int a[],double len)//计算整型数组平均数
{
  double avr,sum=0;
  int i;
  for ( i = 0; i < len; i++)
  {
    sum+=a[i];
  }
  avr=sum/len;
  return avr;
}
void randScore()//产生随机成绩
{
  cout<<"使用随机成绩（默认）"<<endl;
  for (size_t i = 0; i < 10; i++)
  {
    for (size_t j = 0; j < 5; j++)
    {
      scoreByStudent[i][j]=Rand_S(0,100);
    }
  }
}
void randScore_s()//指定最大值、最小值
{
  system("cls");
  cout<<"指定最高、最低分"<<endl;
  int min,max;

  while(1)
  {
    cout<<"请输入最大值、最小值，用空格隔开(整数)"<<'\n';
    cin>>max>>min;
    if (max<0||min<0)
    {
      cout<<"error:输入范围有误（超过下限）"<<'\n';
    }
    else if(max==min)
    {
      cout<<"warning:范围为0（相等值）"<<"\n";
      break;
    }
    else
    {
    if(max<min)
      {
        cout<<"您输入的最大值小于最小值，系统已为您自动修正...."<<'\n';
        int tmp;
        tmp=max;
        max=min;
        min=tmp;
        Sleep(500);
        system("pause");
      }
    break;
    }
  }

  for (size_t i = 0; i < 10; i++)
  {
    for (size_t j = 0; j < 5; j++)
    {
      scoreByStudent[i][j]=Rand_S(min,max);
    }
  }
}
/*
void keyScore()
{
  system("cls");
  cout<<"键盘输入成绩"<<endl;
}
*/
int main(int argc, char const *argv[]) {
  welcom();
  srand((unsigned int)(time(NULL)));
  int s=1;
  cout<<"请选择要使用模式:"<<'\n';
  cout<<"1.测试模式1：使用随机成绩（默认，范围：0-100）"<<'\n';
  cout<<"2.测试模式2：指定最高、最低分"<<'\n';
//  cout<<"3.测试模式3：键盘输入成绩"<<'\n';
  cin>>s;
  switch (s)
  {
    default: randScore();break;
    case 2:  randScore_s();break;
 //   case 3:  keyScore();break;
  }
  system("cls");
  int studentMax=0,subjectMax=0,scoreMax;
  scoreMax=scoreByStudent[0][0];
  //打印学生成绩表格
  cout<<"学生成绩表"<<'\n';
  cout<<"学生\t科目1\t科目2\t科目3\t科目4\t科目5"<<'\n';
  for (size_t i = 0; i < 10; i++)
  {
    cout<<i+1<<'\t';
    for (size_t j = 0; j < 5; j++)
    {
      cout<<scoreByStudent[i][j]<<'\t';
      if(scoreMax<scoreByStudent[i][j])//寻找最大值所在位置
      {
        scoreMax=scoreByStudent[i][j];
        studentMax=i;
        subjectMax=j;
      }
    }
    cout<<'\n';
  }
  system("pause");
  system("cls");
//转置：从以学生为列到以科目为列
  for (size_t i = 0; i < 10; i++)
  {
    for (size_t j = 0; j < 5; j++)
    {
      scoreBySubject[j][i]=scoreByStudent[i][j];
    }
  }
  cout<<"*学生*\t*平均成绩*"<<'\n';
  for (size_t i = 0; i < 10; i++)
  {
    cout<<"  "<<i+1<<'\t'<<"  "<<avr(scoreByStudent[i],5)<<'\n';
  }
  cout<<'\n';
  cout<<"*科目*\t*平均成绩*"<<'\n';
  for (size_t i = 0; i < 5; i++)
  {
    cout<<"  "<<i+1<<'\t'<<"  "<<avr(scoreBySubject[i],10)<<'\n';
  }
  cout<<"\n*最高分是第<"<<studentMax+1<<">名同学的第<"<<subjectMax+1<<">科";
  cout<<"分数为<"<<scoreMax<<">分\n\n";
  system("pause");
  return 0;
}
