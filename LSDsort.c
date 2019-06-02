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
	for(int i=0;i<size;++i)
	{
	    int index=array[i]/a%10;
	    count[index]++;
	}

	int arr[10]={0};

	for(int i=1;i<size;++i)
	{
	    arr[i]=count[i-1]+arr[i-1];
	}

	memset(tmp,0,sizeof(int)*size);

	for(int i=0;i<size;++i)
	{
	    int index=array[i]/a%10;
	    tmp[arr[index]++]=array[i];
	}

	memcpy(array,tmp,sizeof(int)*size);
	a*=10;
    }

    free(tmp);
    tmp=NULL;
}

void PrintArray(int* array,int size)
{
    for(int i=0;i<size;++i)
    {
	printf("%d ",array[i]);
    }
    printf("\n");
}

int main()
{
    int array[10]={123,375,914,627,285,547,423,761,834,380};
    LSDsort(array,sizeof(array)/sizeof(array[0]));

    PrintArray(array,sizeof(arrat)/sizeof(array[0]));
    return 0;
}
