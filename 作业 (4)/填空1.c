#include <stdio.h>
#include <string.h>
int main()
{
    char s[80],t[80];
    int i;
    int m;
    printf("ÊäÈë×Ö·û´®£º" );
    scanf("%s",s);
    m=strlen(s);
    for(i=0;i<m;i++)
            t[i]=s[i];
    for(i=0;i<m;i++)
            t[m+i]=s[m-i-1];
    t[m+i]='\0';
      printf("ĞÂµÄ×Ö·û´®£º%s\n",t);
	return 0;
}
