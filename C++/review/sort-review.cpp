#include <iostream>

using namespace std;

void insertSort(int* array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;

		while (key < array[end] && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}

		array[end + 1] = key;
	}
}

void shellSort(int* array, int size)
{
	int gap = size;

	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = gap; i < size; ++i)
		{
			int key = array[i];
			int end = i - gap;

			while (key < array[end] && end >= 0)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

#if 0
void selectSort(int* array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int maxPos = 0;

		for (int j = 0; j < size - i; ++j)
		{
			if (array[maxPos] < array[j])
			{
				maxPos = j;
			}

			if (maxPos != size - i - 1)
			{
				swap(array[maxPos], array[size - i - 1]);
			}
		}
	}
}
#endif

#if 0
void selectDSort(int* array, int size)
{
	int begin = 0;
	int end = size - 1;

	while (begin < end)
	{
		int maxPos = begin;
		int minPos = begin;
		int index = begin + 1;

		while (index <= end)
		{
			if (array[maxPos] < array[index])
			{
				maxPos = index;
			}

			if (array[minPos]>array[index])
			{
				minPos = index;
			}
			++index;
		}

		if (minPos == end)
		{
			minPos = maxPos;
		}

		if (minPos != begin)
		{
			swap(array[begin], array[minPos]);
		}

		if (maxPos != end)
		{
			swap(array[end], array[maxPos]);
		}

		begin++;
		end--;
	}
}
#endif


void printAll(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

int GetMidIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);

	//a b
	if (array[left] < array[right - 1])
	{
		//c<a ,a就是mid
		if (array[mid] < array[left])
		{
			return left;
		}
		//c>b,b就是mid
		else if (array[mid]>array[right - 1])
		{
			return right - 1;
		}
		else
		{
			return mid;
		}
	}
	else
	{
		//b a,c<b,b就是mid
		if (array[mid] < array[right - 1])
		{
			return right - 1;
		}
		//b a,c>a,a就是mid
		else if (array[mid]>array[left])
		{
			return left;
		}
		else
		{
			return mid;
		}
	}
}

int partion(int* array, int left, int right)
{
	int mid = GetMidIndex(array, left, right);

	swap(array[mid], array[right - 1]);

	int begin = left;
	int end = right - 1;

	int key = array[right - 1];

	while (begin<end)
	{
		//从左往右找比基准值大的元素
		while (begin < end&&array[begin] <= key)
		{
			begin++;
		}

		//从右往左找比基准值小的元素
		while (begin < end&&array[end] >= key)
		{
			end--;
		}

		//找到之后
		if (begin != end)
		{
			swap(array[begin], array[end]);
		}
	}

	//放置基准值
	if (begin != right - 1)
	{
		swap(array[begin], array[right - 1]);
	}

	return begin;
}

void QuickDSort(int* array, int left, int right)
{
	if (right - left > 1)
	{
		int div = partion(array, left, right);
		QuickDSort(array, left, div);
		QuickDSort(array, div + 1, right);
	}
}

//复习选择排序

//普通的未经过优化的选择排序
void selectSort(int* array, int size)
{
	//思路:从头到尾遍历,找最大的元素,找到之后和最后一个位置的元素交换
	int end = size - 1;

	while (end != 0)
	{
		int max = 0;
		int begin =0;

		for (begin; begin <= end; ++begin)
		{
			if (array[max] < array[begin])
			{
				max = begin;
			}
			continue;
		}

		swap(array[max], array[end]);
		end--;
	}
}

void selectSortD(int* array, int size)
{
	int begin = 0;
	int end = size - 1;

	while (begin < end)
	{
		int index = begin + 1;
		int minpos = begin;
		int maxpos = begin;

		for (index; index <= end; ++index)
		{
			if (array[index]>array[maxpos])
			{
				maxpos = index;
			}

			if (array[index] < array[minpos])
			{
				minpos = index;
			}
		}

		//如果minpos在最后的位置,把minpos的位置与maxpos互换即可
		if (minpos == end)
		{
			minpos = maxpos;
		}

		swap(array[begin], array[minpos]);

		swap(array[end], array[maxpos]);

		begin++;
		end--;
	}
}

#include<assert.h>

void mergeData(int* array,int left,int mid,int right,int* tmp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;

	int index = left;

	while (begin1 < end1 && begin2<end2)
	{
		if (array[begin1] < array[begin2])
		{
			tmp[index] = array[begin1];
			begin1++;
			index++;
		}
		else
		{
			tmp[index] = array[begin2];
			begin2++;
			index++;
		}
	}

	//处理长度不一致的情况

	while (begin1 < end1)
	{
		tmp[index] = array[begin1];
		begin1++;
		index++;
	}

	while (begin2<end2)
	{
		tmp[index] = array[begin2];
		begin2++;
		index++;
	}
}

void _mergeSort(int* array, int left, int right,int* tmp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);

		_mergeSort(array, left, mid, tmp);
		_mergeSort(array, mid, right, tmp);

		mergeData(array, left, mid, right, tmp);

		memcpy(array, tmp , sizeof(int)*(right - left));

	}
}

void mergeSort(int* array, int size)
{
	int* tmp = new int[size];

	_mergeSort(array, 0, size, tmp);

	delete[] tmp;
}

void mergeSortN(int* array, int size)
{
	int* tmp = new int[size];

	int gap = 1;

	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			if (mid > size)
			{
				mid = size;
			}

			if (right > size)
			{
				right = size;
			}

			mergeData(array, left, mid, right, tmp);
		}

		memcpy(array, tmp, sizeof(int)*size);

		gap *= 2;
	}

	delete[] tmp;
}

int main()
{
	//int array[] = { 5, 3, 7, 9, 6 };

	//insertSort(array, sizeof(array) / sizeof(array[0]));
	//shellSort(array, sizeof(array) / sizeof(array[0]));
	//selectSort(array, sizeof(array) / sizeof(array[0]));
	//selectDSort(array, sizeof(array) / sizeof(array[0]));
	//printAll(array, sizeof(array) / sizeof(array[0]));

	int array[] = { 3, 4, 2, 9, 1, 7, 6, 0, 8, 5 };
	//QuickDSort(array, 0, sizeof(array) / sizeof(array[0]));

	//selectSort(array, sizeof(array) / sizeof(array[0]));
	//selectSortD(array, sizeof(array) / sizeof(array[0]));
	//mergeSort(array, sizeof(array) / sizeof(array[0]));
	mergeSortN(array, sizeof(array) / sizeof(array[0]));

	printAll(array, sizeof(array) / sizeof(array[0]));

	system("pause");
	return 0;
}
