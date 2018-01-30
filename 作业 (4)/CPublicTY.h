/*
Copyright XuTianyi,2017
定义一些课程中常用的C/C++函数方便使用
version 0.0.1 alpha

包含内容：
冒泡排序（整型，定长）*2
冒泡排序（整型，全部）*2——未完成
冒泡排序（float，定长）*2
定义上下限的随机数 *1
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

// 使用冒泡排序法重排数组，从小到大，整型，排列前n个数，使用方式为 “BubbleSort_FS_l(数组,排序个数)”
void BubbleSort_FS_l(int a[],int len)
{
  int i,j,temp;
  for (i = 0;i<len; i++)
      {
        for ( j = 0; j<len-i; j++)
            if (a[j] < a[j+1])
            {
                  temp = a[j];
                  a[j] = a[j+1];
                  a[j+1] = temp;
            }
      }
}


// 使用冒泡排序法重排数组，从大到小，整型，排列前n个数，使用方式为 “BubbleSort_FB_l(数组,排序个数)”
void BubbleSort_FB_l(int a[],int len)
{
  int i,j,temp;
  len=len-1;
  for (i = 0;i<len; i++)
      {
        for ( j = 0; j<len-i; j++)
            if (a[j] > a[j+1])
            {
                  temp = a[j];
                  a[j] = a[j+1];
                  a[j+1] = temp;
            }
      }
}


//总出现莫名其妙的问题，等想明白再改改,这个后面还有一个从大到小的
// 使用冒泡排序法重排数组，从小到大，整型，排列前n个数，使用方式为 “BubbleSort_FS(数组)”
/*
void BubbleSort_FS(int a[])
{
  int temp,len=1,i,j;
  for (i = 0; a[i]!='\0'; i++)
  {
    len++;
  }
  for (i = 0;i<len; i++)
      {
        for (j = 0; j<len-i; j++)
            if (a[j] > a[j+1])
            {
                  temp = a[j];
                  a[j] = a[j+1];
                  a[j+1] = temp;
            }
      }
}
*/

// 使用冒泡排序法重排数组，从小到大，数组float，长度整型，排列前n个数，使用方式为 “BubbleSort_FS_l(数组,排序个数)”
void BubbleSort_FSf_l(float a[],int len)
{
  int i,j;
  float temp;
  for (i = 0;i<len; i++)
      {
        for ( j = 0; j<len-i; j++)
            if (a[j] > a[j+1])
            {
                  temp = a[j];
                  a[j] = a[j+1];
                  a[j+1] = temp;
            }
      }
}

// 使用冒泡排序法重排数组，从大到小，数组float，长度整型，排列前n个数，使用方式为 “BubbleSort_FB_l(数组,排序个数)”
void BubbleSort_FBf_l(float a[],int len)
{
  int i,j;
  float temp;
  len=len-1;
  for (i = 0;i<len; i++)
      {
        for ( j = 0; j<len-i; j++)
            if (a[j] < a[j+1])
            {
                  temp = a[j];
                  a[j] = a[j+1];
                  a[j+1] = temp;
            }
      }
}

//带上下限的整型随机数,整型，用法： "Rand_S(下限，上限)",需要使用 “srand((unsigned int)(time(NULL)))”初始化 rand（）
int Rand_S(int m,int n)
{
  int rand_num;
  rand_num=(rand()%(n-m+1)+m);
  return rand_num;
}

//计算文件行数,使用完后需要重新打开文件
int FILE_LINE(FILE *fp)
{
  int fline=0;
  char null[10000];
  while ((fgets(null,10000,fp))!=NULL)
  fline++;
  return fline;
}

//md5算法加密，待补充
