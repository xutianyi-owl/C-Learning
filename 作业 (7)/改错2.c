#include <stdio.h>
#include <string.h>
int  main()
{
    char str1[80];
    int i,len;
    char temp;
    FILE *fp;
    printf("Enter Str1: \n");
    gets(str1);
    len = strlen(str1);
    for (i=0; i<len/2; i++)
    {
        temp = str1[i];
        str1[i] = str1[len-1-i];
        str1[len-1-i] = temp;
    }
    printf("Result is: %s\n",str1);
    fp = fopen("result.txt","w");
    fprintf(fp,"Result is: %s\n",str1);
    fclose(fp);
    return 0;
}
