#include <iostream>
#include "cPublicTY.h"
using namespace std;
int scoreByStudent[10][5];
int scoreBySubject[5][10];
void welcom()   //��������д�ˣ����ϴεİ�
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
double avr(int a[],double len)//������������ƽ����
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
void randScore()//��������ɼ�
{
  cout<<"ʹ������ɼ���Ĭ�ϣ�"<<endl;
  for (size_t i = 0; i < 10; i++)
  {
    for (size_t j = 0; j < 5; j++)
    {
      scoreByStudent[i][j]=Rand_S(0,100);
    }
  }
}
void randScore_s()//ָ�����ֵ����Сֵ
{
  system("cls");
  cout<<"ָ����ߡ���ͷ�"<<endl;
  int min,max;

  while(1)
  {
    cout<<"���������ֵ����Сֵ���ÿո����(����)"<<'\n';
    cin>>max>>min;
    if (max<0||min<0)
    {
      cout<<"error:���뷶Χ���󣨳������ޣ�"<<'\n';
    }
    else if(max==min)
    {
      cout<<"warning:��ΧΪ0�����ֵ��"<<"\n";
      break;
    }
    else
    {
    if(max<min)
      {
        cout<<"����������ֵС����Сֵ��ϵͳ��Ϊ���Զ�����...."<<'\n';
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
  cout<<"��������ɼ�"<<endl;
}
*/
int main(int argc, char const *argv[]) {
  welcom();
  srand((unsigned int)(time(NULL)));
  int s=1;
  cout<<"��ѡ��Ҫʹ��ģʽ:"<<'\n';
  cout<<"1.����ģʽ1��ʹ������ɼ���Ĭ�ϣ���Χ��0-100��"<<'\n';
  cout<<"2.����ģʽ2��ָ����ߡ���ͷ�"<<'\n';
//  cout<<"3.����ģʽ3����������ɼ�"<<'\n';
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
  //��ӡѧ���ɼ����
  cout<<"ѧ���ɼ���"<<'\n';
  cout<<"ѧ��\t��Ŀ1\t��Ŀ2\t��Ŀ3\t��Ŀ4\t��Ŀ5"<<'\n';
  for (size_t i = 0; i < 10; i++)
  {
    cout<<i+1<<'\t';
    for (size_t j = 0; j < 5; j++)
    {
      cout<<scoreByStudent[i][j]<<'\t';
      if(scoreMax<scoreByStudent[i][j])//Ѱ�����ֵ����λ��
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
//ת�ã�����ѧ��Ϊ�е��Կ�ĿΪ��
  for (size_t i = 0; i < 10; i++)
  {
    for (size_t j = 0; j < 5; j++)
    {
      scoreBySubject[j][i]=scoreByStudent[i][j];
    }
  }
  cout<<"*ѧ��*\t*ƽ���ɼ�*"<<'\n';
  for (size_t i = 0; i < 10; i++)
  {
    cout<<"  "<<i+1<<'\t'<<"  "<<avr(scoreByStudent[i],5)<<'\n';
  }
  cout<<'\n';
  cout<<"*��Ŀ*\t*ƽ���ɼ�*"<<'\n';
  for (size_t i = 0; i < 5; i++)
  {
    cout<<"  "<<i+1<<'\t'<<"  "<<avr(scoreBySubject[i],10)<<'\n';
  }
  cout<<"\n*��߷��ǵ�<"<<studentMax+1<<">��ͬѧ�ĵ�<"<<subjectMax+1<<">��";
  cout<<"����Ϊ<"<<scoreMax<<">��\n\n";
  system("pause");
  return 0;
}
