#include <iostream>
using namespace std;
void cov_Order(long n,int p)
{
    int c,m=0,s[100];
    while (n!=0)//����ת���������������s[m]
    {
        c=n%p;
        n=n/p;
        m++;s[m]=c;   //��������˳���������s[m]��
    }
    for(int k=m;k>=1;k--)//���ת���������
    {
        if(s[k]>=10) //��Ϊʮ�����Ƶ���������Ӧ����ĸ
            cout<<(char)(s[k]+55);
        else         //����ֱ���������
            cout<<s[k];
    }

}

int main(int argc, char const *argv[]) {
  cout<<"������Ҫת�������֣���������"<<endl;
  long n;
  cin>>n;
  cout<<"������Ϊ:";
  cov_Order(n,2);
  cout<<endl;
  cout<<"ʮ������Ϊ:";
  cov_Order(n,16); 
  cout<<endl;
  cout<<"�˽���Ϊ:";
  cov_Order(n,8);
  cout<<endl;
  system("pause");
  return 0;
}
