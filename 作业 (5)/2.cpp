#include <iostream>
#include <math.h>
using namespace std;
double Dist(double x1,double y1,double x2,double y2)
{
  double dis;
  dis=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
  return dis;
}

int main(int argc, char const *argv[]) {
  cout<<"������ x1,x2,y1,y2,�ÿո����"<<endl;
  double x1,x2,y1,y2;
  cin>>x1>>x2>>y1>>y2;
  cout<<"�����ǣ�"<<Dist(x1,x2,y1,y2)<<endl;
  system("pause");
  return 0;
}
