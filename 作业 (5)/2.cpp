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
  cout<<"请输入 x1,x2,y1,y2,用空格隔开"<<endl;
  double x1,x2,y1,y2;
  cin>>x1>>x2>>y1>>y2;
  cout<<"距离是："<<Dist(x1,x2,y1,y2)<<endl;
  system("pause");
  return 0;
}
