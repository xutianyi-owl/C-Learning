#include <stdio.h>
int main(int argc, char const *argv[]) {
  char c;
  int spc_count=0,chr_count=0,num_count=0,oth_count=0;
  /*�����ַ�*/
  while ((c=getchar())!='\n' )
  {
    /*����*/
    if (c==' ')
    spc_count++;
    else if(c>='a'&&c<='z'||c>='A'&&c<='Z')
    chr_count++;
    else if(c>='0'&&c<='9')
    num_count++;
    else
    oth_count++;
  }
  printf(" �ո��� %d ��\n ��ĸ�� %d ��\n ������ %d ��\n �����ַ��� %d ��\n",spc_count,chr_count,num_count,oth_count );
  return 0;
}
