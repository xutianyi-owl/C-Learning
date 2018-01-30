#include <stdio.h>
int main(int argc, char const *argv[]) {
  char c;
  int spc_count=0,chr_count=0,num_count=0,oth_count=0;
  /*输入字符*/
  while ((c=getchar())!='\n' )
  {
    /*计数*/
    if (c==' ')
    spc_count++;
    else if(c>='a'&&c<='z'||c>='A'&&c<='Z')
    chr_count++;
    else if(c>='0'&&c<='9')
    num_count++;
    else
    oth_count++;
  }
  printf(" 空格有 %d 个\n 字母有 %d 个\n 数字有 %d 个\n 其他字符有 %d 个\n",spc_count,chr_count,num_count,oth_count );
  return 0;
}
