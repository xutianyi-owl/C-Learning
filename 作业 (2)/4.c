#include <stdio.h>
int main(int argc, char const *argv[]) {
  char chr[80];
  int k;
  printf("请输入要加密的字符串，不超过80个字符，以回车键结束\n");
  gets(chr);
  printf("请输入加密序数\n");
  scanf("%d",&k);
  /*开始加密*/
  for (size_t i = 0; chr[i]!='\0'; i++)
  {
    if(chr[i]>='a'&&chr[i]<='z')
    {
      chr[i]=chr[i]+k;
      while (chr[i]>='z')
      {
        chr[i]=chr[i]-26;
        if(chr[i]>='z')
        continue;
      }
    }

    if(chr[i]>='A'&&chr[i]<='Z')
    {
      chr[i]=chr[i]+k;
      while (chr[i]>='Z')
      {
        chr[i]=chr[i]-26;
        if(chr[i]>='Z')
        continue;
      }
    }

  }
  /*输出加密后的字符串*/
  printf("%s",chr);
  printf("\n加密结束\n");
  return 0;
}
