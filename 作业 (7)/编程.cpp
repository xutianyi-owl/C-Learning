#include <iostream>
#include <string>
using namespace std;

int check_firstNum(string a) //����һ���ַ��ǲ������֣������ַ��� 0�����Ƿ��� 1
{
  if (a[0]>='0'&&a[0]<='9')
  return 0;
  else
  return 1;
}

int check_specchar(string a) //����Ƿ���ڷǷ������ַ������ڷ���λ��
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
  cout<<"������Ҫ���ı�ʶ��\n";
  cin>>strToCheck;
  if(check_firstNum(strToCheck)==0)
  {
    cout<<"error���� 1 ���ַ�����Ϊ ����: "<<strToCheck[0]<<'\n';
  }
  else if(check_specchar(strToCheck)!=0)
  {
    cout<<"error: ��"<<check_specchar(strToCheck)+1<<"���ַ�Ϊ�Ƿ������ַ�:";
    cout<<strToCheck[check_specchar(strToCheck)]<<'\n';
  }
  else
  {
    cout<<"Yes\n";
  }
  return 0;
}
