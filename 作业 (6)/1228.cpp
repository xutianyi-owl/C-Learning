#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/* 全局变量 */
string worker[10][2];
ifstream _dataInUse;
int inputState=2;
/* 相关函数 */
int loadFile()  //检测数据文件是否存在,存在则返回 1
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

void sortByNo( string data[10][2], int line) //按照工号从小到大排列
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

void intputData() //输入数据，同时返回确认情况,确认返回 1
{
  system("cls");
  cout<<"*输入数据\n*提示：数据将同时保存在程序目录 workerdata 文件中\n";
  ofstream _WriteData;
  _WriteData.open("workerdata");
  cout<<"请输入依次输入 10 个职工姓名和职工编号"<<'\n';
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
  cout<<"输入结束，确认完成？\n1.确定\n2.放弃";
  cin>>inputState;
  if(inputState==2)
  {
    cout<<"将使用默认数据\n";
    remove("workerdata");
    system("pause");
  }
} //输入数据结束

void lookUP(string num,string data[10][2])  //二分法查找数字
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
  cout<<"已经找到："<<data[mid][0]<<'\n';
  else
  cout<<"数据不存在\n";
  system("pause");
}

void dataCheck()  //检测使用的数据来源
{
  if(loadFile()==1&&inputState==2)
  {
    cout<<"** 正在使用默认数据 **\n\n";
    _dataInUse.open("workerdata_default");
  }
  else if(loadFile()==0&&inputState==2)
  {
    cout<<"** 未输入数据或默认数据丢失，请重新输入数据 **\n\n";
    system("pause");
    intputData();
  }
  else if(inputState==1)
  {
    cout<<"** 正在使用输入的数据 **\n\n";
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

int menu() //显示主菜单和选项
{
  system("cls");
  cout<<"请选择要使用的功能"<<'\n';
  cout<<"1.输入数据"<<'\n';
  cout<<"2.查看按工号从小到大顺序的列表"<<'\n';
  cout<<"3.按工号查找职工"<<'\n';
  cout<<"4.退出"<<'\n';
  cout<<"\n*输入选项对应编号进行选择"<<'\n';
  int choice=0;
  cin>>choice;
  return choice;
}

/* 主函数 */
int main(int argc, char const *argv[])
{
  while(1)
  {
    switch(menu())
    {
      case 1 : intputData(); break; //输入数据
      case 2 : //输出排列结果
      {
        dataCheck();
        system("cls");
        sortByNo(worker,10);
        /* 显示排列好的内容 */
        for (size_t i = 0; i < 10; i++)
        {
          for (size_t j = 0; j < 2; j++)
          {
            cout<<worker[i][j];
            if(j<1) cout<<'\t';
          }
          cout<<"\n";
        }
        cout<<"*显示完毕\n";
        system("pause");
        break;
      } //排列结束
      case 3 :  //查找工号
      {
        system("cls");
        dataCheck();
        sortByNo(worker,10);
        string num;
        cout<<"请输入要查找的工号\n";
        cin>>num;
        lookUP(num,worker);
        break;
      } //查找工号结束
      case 4 : exit(0); //退出程序
    }
  }
  return 0;
}
