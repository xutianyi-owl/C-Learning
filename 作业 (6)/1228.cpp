#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/* ȫ�ֱ��� */
string worker[10][2];
ifstream _dataInUse;
int inputState=2;
/* ��غ��� */
int loadFile()  //��������ļ��Ƿ����,�����򷵻� 1
{
  fstream _ReadData;
  _ReadData.open("workerdata_default",ios::in);
  if (!_ReadData)
  {
    _ReadData.close();
    return 0;
  }
  else
  {
    _ReadData.close();
    return 1;
  }
}

void sortByNo( string data[10][2], int line) //���չ��Ŵ�С��������
{
  string temp0,temp1;
  for (size_t i = 0;i<line-1; i++)
      {
        for ( size_t j = 0; j<line-1-i; j++)
            if (data[j][1] > data[j+1][1])
            {
                  temp0 = data[j][0];
                  data[j][0] = data[j+1][0];
                  data[j+1][0] = temp0;
                  temp1 = data[j][1];
                  data[j][1] = data[j+1][1];
                  data[j+1][1] = temp1;
            }
      }
}

void intputData() //�������ݣ�ͬʱ����ȷ�����,ȷ�Ϸ��� 1
{
  system("cls");
  cout<<"*��������\n*��ʾ�����ݽ�ͬʱ�����ڳ���Ŀ¼ workerdata �ļ���\n";
  ofstream _WriteData;
  _WriteData.open("workerdata");
  cout<<"�������������� 10 ��ְ��������ְ�����"<<'\n';
  for (size_t i = 0; i < 10; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      cin>>worker[i][j];
      _WriteData<<worker[i][j];
      if(j<1) _WriteData<<" ";
    }
    if(i<9) _WriteData<<'\n';
  }
  _WriteData.close();
  cout<<"���������ȷ����ɣ�\n1.ȷ��\n2.����";
  cin>>inputState;
  if(inputState==2)
  {
    cout<<"��ʹ��Ĭ������\n";
    remove("workerdata");
    system("pause");
  }
} //�������ݽ���

void lookUP(string num,string data[10][2])  //���ַ���������
{
  int front=0,end=9,mid;
  mid=(front+end)/2;
  while(front<end&&data[mid][1]!=num)
  {
    if(data[mid][1]<num) front=mid+1;
    if(data[mid][1]>num) end=mid-1;
    mid=(front+end)/2;
  }
  if(data[mid][1]==num)
  cout<<"�Ѿ��ҵ���"<<data[mid][0]<<'\n';
  else
  cout<<"���ݲ�����\n";
  system("pause");
}

void dataCheck()  //���ʹ�õ�������Դ
{
  if(loadFile()==1&&inputState==2)
  {
    cout<<"** ����ʹ��Ĭ������ **\n\n";
    _dataInUse.open("workerdata_default");
  }
  else if(loadFile()==0&&inputState==2)
  {
    cout<<"** δ�������ݻ�Ĭ�����ݶ�ʧ���������������� **\n\n";
    system("pause");
    intputData();
  }
  else if(inputState==1)
  {
    cout<<"** ����ʹ����������� **\n\n";
    _dataInUse.open("workerdata");
  }
  for (size_t i=0 ; i<10 ; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
        _dataInUse>>worker[i][j];
    }
  }
  _dataInUse.close();
}

int menu() //��ʾ���˵���ѡ��
{
  system("cls");
  cout<<"��ѡ��Ҫʹ�õĹ���"<<'\n';
  cout<<"1.��������"<<'\n';
  cout<<"2.�鿴�����Ŵ�С����˳����б�"<<'\n';
  cout<<"3.�����Ų���ְ��"<<'\n';
  cout<<"4.�˳�"<<'\n';
  cout<<"\n*����ѡ���Ӧ��Ž���ѡ��"<<'\n';
  int choice=0;
  cin>>choice;
  return choice;
}

/* ������ */
int main(int argc, char const *argv[])
{
  while(1)
  {
    switch(menu())
    {
      case 1 : intputData(); break; //��������
      case 2 : //������н��
      {
        dataCheck();
        system("cls");
        sortByNo(worker,10);
        /* ��ʾ���кõ����� */
        for (size_t i = 0; i < 10; i++)
        {
          for (size_t j = 0; j < 2; j++)
          {
            cout<<worker[i][j];
            if(j<1) cout<<'\t';
          }
          cout<<"\n";
        }
        cout<<"*��ʾ���\n";
        system("pause");
        break;
      } //���н���
      case 3 :  //���ҹ���
      {
        system("cls");
        dataCheck();
        sortByNo(worker,10);
        string num;
        cout<<"������Ҫ���ҵĹ���\n";
        cin>>num;
        lookUP(num,worker);
        break;
      } //���ҹ��Ž���
      case 4 : exit(0); //�˳�����
    }
  }
  return 0;
}
