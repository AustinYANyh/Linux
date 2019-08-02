#include "heap.h"
#include<assert.h>
#include<iostream>
#include<algorithm>

using namespace std;

bool Less(HpDataType a, HpDataType b)
{
	return a < b;
}

bool Big(HpDataType a, HpDataType b)
{
	return a > b;
}

void InitHeap(Heap* hp, HpDataType* array, int size, Compare compare)
{
	assert(hp);

	try
	{
		hp->_array = new HpDataType[size];
	}
	catch (...)
	{
		cout << "申请空间错误!" << endl;
	}

	hp->_capacity = size;

	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = array[i];
	}

	hp->_size = size;

	//最重要的一句,少这一句compare的方法会无法调用
	hp->compare = compare;

	//空间申请完毕,数据拷贝完毕,开始调整,满足堆的性质
	int lastleaf = (size - 2) >> 1;

	while (lastleaf >= 0)
	{
		AdjustDown(hp->_array, hp->_size, lastleaf, hp->compare);
		lastleaf--;
	}

}

void AdjustDown(int* array, int size, int parent,Compare compare)
{
	int child = parent * 2 + 1;

	//找出较小的孩子,循环比较
	while (child < size)
	{
		//使用左右孩子比较,必须保证右孩子存在
		if (child + 1 < size && compare(array[child + 1], array[child]))
		{
			child += 1;
		}

		if (compare(array[child], array[parent]))
		{
			swap(array[child], array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			//已经满足堆的特性.不需要在继续
			break;
		}
	}
}

void AdjustUp(int* array, int size, int parent, Compare compare)
{

}

void HeapAdjust(int* array, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		if (array[child] > array[parent])
		{
			swap(array[child], array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapSort(int* array, int size)
{
	int root = ((size - 1) >> 1);
	for (root; root >= 0; --root)
	{
		HeapAdjust(array, size, root);
	}


	int end = size - 1;
	while (end != 0)
	{
		swap(array[0], array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

void PrintData(Heap* hp)
{
	for (int i = 0; i < hp->_size; ++i)
	{
		cout << hp->_array[i] << " ";
	}
	cout << endl;
}

void DestroyHeap(Heap* hp)
{
	assert(hp);

	if (hp->_array)
	{
		delete[] hp->_array;
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

int main()
{
	Heap hp;

	//int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };

	//InitHeap(&hp, array, sizeof(array) / sizeof(array[0]),Less);

	//PrintData(&hp);

	int array[] = { 2, 3, 8, 0, 9, 1, 7, 4, 6, 5 };

	InitHeap(&hp, array, sizeof(array) / sizeof(array[0]), Less);

	PrintData(&hp);

	HeapSort(array, sizeof(array) / sizeof(array[0]));

	for (auto e : array)
	{
		cout << e << endl;
	}

	DestroyHeap(&hp);

	system("pause");
	return 0;
}