#include <iostream>
#include <string>
using namespace std;

int check_firstNum(string a) //检查第一个字符是不是数字，是数字返回 0，不是返回 1
{
  if (a[0]>='0'&&a[0]<='9')
  return 0;
  else
  return 1;
}

int check_specchar(string a) //检查是否存在非法特殊字符，存在返回位置
{
  int posi;
  int len=a.length();
  for (size_t i = 0; i < len; i++)
  {
    if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'||a[i]=='_'||a[i]>='0'&&a[i]<='9')
    {
      posi=0;
    }
    else
    {
      posi=i;
      break;
    }
  }
  return posi;
}

int main(int argc, char const *argv[]) {
  string strToCheck;
  cout<<"请输入要检查的标识符\n";
  cin>>strToCheck;
  if(check_firstNum(strToCheck)==0)
  {
    cout<<"error：第 1 个字符不能为 数字: "<<strToCheck[0]<<'\n';
  }
  else if(check_specchar(strToCheck)!=0)
  {
    cout<<"error: 第"<<check_specchar(strToCheck)+1<<"个字符为非法特殊字符:";
    cout<<strToCheck[check_specchar(strToCheck)]<<'\n';
  }
  else
  {
    cout<<"Yes\n";
  }
  return 0;
}
