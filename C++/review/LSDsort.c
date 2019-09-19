/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：LSDsort.c
*   创 建 者：闫云皓
*   创建日期：2019年06月03日
*   描    述：
*
================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <malloc.h>

void LSDsort(int* array,int size,int n)
{
    int* tmp=(int*)malloc(sizeof(int)*size);
    int a=1;

    while(n--!=0)
    {
	int count[10]={0};

	//统计每一位出现相同数字的个数
	int i=0;
	for(i=0;i<size;++i)
	{
	    int index=array[i]/a%10;
	    count[index]++;
	}

	int arr[10]={0};

	int j=1;
	for(j=1;j<size;++j)
	{
	    arr[j]=count[j-1]+arr[j-1];
	}

	memset(tmp,0,sizeof(int)*size);

	int k=0;
	for(k=0;k<size;++k)
	{
	    int index=array[k]/a%10;
	    tmp[arr[index]++]=array[k];
	}

	memcpy(array,tmp,sizeof(int)*size);
	a*=10;
    }

    free(tmp);
    tmp=NULL;
}

void PrintArray(int* array,int size)
{
    int i=0;
    for(i=0;i<size;++i)
    {
	printf("%d ",array[i]);
    }
    printf("\n");
}

int main()
{
    int array[10]={123,375,914,627,285,547,423,761,834,380};
    LSDsort(array,sizeof(array)/sizeof(array[0]),3);

    PrintArray(array,sizeof(array)/sizeof(array[0]));
    return 0;
}
