#include <iostream>
using namespace std;
void cov_Order(long n,int p)
{
    int c,m=0,s[100];
    while (n!=0)//数制转换，结果存入数组s[m]
    {
        c=n%p;
        n=n/p;
        m++;s[m]=c;   //将余数按顺序存入数组s[m]中
    }
    for(int k=m;k>=1;k--)//输出转换后的序列
    {
        if(s[k]>=10) //若为十六进制等则输出相对应的字母
            cout<<(char)(s[k]+55);
        else         //否则直接输出数字
            cout<<s[k];
    }

}

int main(int argc, char const *argv[]) {
  cout<<"请输入要转换的数字（正整数）"<<endl;
  long n;
  cin>>n;
  cout<<"二进制为:";
  cov_Order(n,2);
  cout<<endl;
  cout<<"十六进制为:";
  cov_Order(n,16); 
  cout<<endl;
  cout<<"八进制为:";
  cov_Order(n,8);
  cout<<endl;
  system("pause");
  return 0;
}
