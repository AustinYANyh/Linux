//数据结构复习
#include <iostream>
#include<cstdio>

using namespace std;

#if 0
struct ListNode
{
	ListNode(int data) :_data(data), pNext(nullptr)
	{

	}

	int _data;
	ListNode* pNext;
};

void PushBack(ListNode*& pHead, int data)
{
	if (pHead == nullptr)
	{
		pHead = new ListNode(data);
	}

	else
	{
		ListNode* pCur = pHead;

		while (pCur->pNext != nullptr)
		{
			pCur = pCur->pNext;
		}

		pCur->pNext = new ListNode(data);
	}
}

void PrintList(ListNode* pHead)
{
	while (pHead != nullptr)
	{
		cout << pHead->_data << "--->";
		pHead = pHead->pNext;
	}
	cout << "nullptr";
	cout << endl;
}

ListNode* reverseList(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* result = nullptr;
	ListNode* pCur = pHead;

	while (pCur != nullptr)
	{
		ListNode* next = pCur->pNext;

		pCur->pNext = result;
		result = pCur;
		pCur = next;
	}
	return result;
}

ListNode* FindMidNode(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* pFast = pHead;
	ListNode* pSlow = pHead;

	while (pFast!= nullptr && pFast->pNext != nullptr)
	{
		pFast = pFast->pNext->pNext;
		pSlow = pSlow->pNext;
	}

	return pSlow;
}

ListNode* FindLastKNode(ListNode* pHead,size_t k)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* pFast = pHead;
	ListNode* pSlow = pHead;

	while (k--)
	{
		//K大于链表长度
		if (pFast == nullptr)
		{
			return nullptr;
		}

		pFast = pFast->pNext;
	}

	while (pFast != nullptr && pFast->pNext != nullptr)
	{
		pFast = pFast->pNext->pNext;
		pSlow = pSlow->pNext;
	}

	return pSlow;
}

ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
	{
		return pHead2;
	}

	if (pHead2 == nullptr)
	{
		return pHead1;
	}

	ListNode* result = nullptr;
	ListNode* last = nullptr;
	ListNode* pCur1 = pHead1;
	ListNode* pCur2 = pHead2;

	while (pCur1 != nullptr && pCur2 != nullptr)
	{
		if (pCur1->_data < pCur2->_data)
		{
			if (result == nullptr)
			{
				result = last = pCur1;
			}
			else
			{
				last->pNext = pCur1;
				last = pCur1;
			}
			pCur1 = pCur1->pNext;
		}
		else
		{
			if (result == nullptr)
			{
				result = last = pCur2;
			}
			else
			{
				last->pNext = pCur2;
				last = pCur2;
			}
			pCur2 = pCur2->pNext;
		}
	}

	if (pCur1 != nullptr)
	{
		last->pNext = pCur1;
	}

	if (pCur2 != nullptr)
	{
		last->pNext = pCur2;
	}

	return result;
}

ListNode* getIntersectionNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr || pHead2 == nullptr)
	{
		return nullptr;
	}

	ListNode* pCur1 = pHead1;
	ListNode* pCur2 = pHead2;

	size_t size1 = 1;
	size_t size2 = 1;

	while (pCur1 != nullptr)
	{
		size1++;
		pCur1 = pCur1->pNext;
	}

	while (pCur2 != nullptr)
	{
		size2++;
		pCur2 = pCur2->pNext;
	}

	pCur1 = pHead1;
	pCur2 = pHead2;

	if (size1 > size2)
	{
		while (size1 > size2)
		{
			pCur1 = pCur1->pNext;
			size1--;
		}
	}
	else
	{
		while (size2 > size1)
		{
			pCur2 = pCur2->pNext;
			size2--;
		}
	}

	while (pCur1 != nullptr && pCur2 != nullptr)
	{
		if (pCur1 == pCur2)
		{
			return pCur1;
		}

		pCur1 = pCur1->pNext;
		pCur2 = pCur2->pNext;
	}

	return nullptr;
}

bool hasCycle(struct ListNode *head)
{
	if (head == nullptr || head->pNext == nullptr)
	{
		return false;
	}
	struct ListNode * pFast = head;
	struct ListNode * pSlow = head;

	while (pFast != nullptr && pFast->pNext != nullptr)
	{
		pFast = pFast->pNext->pNext;
		pSlow = pSlow->pNext;

		if (pFast == pSlow)
		{
			return true;
		}
	}
	return false;
}

#if 0
ListNode* getIntersectionNodeWithCircle(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
	{
		return nullptr;
	}

	if (pHead2 == nullptr)
	{
		return nullptr;
	}

	if (hasCycle(pHead1) == false && hasCycle(pHead2) == false)
	{
		//两个都不带环
		getIntersectionNode(pHead1, pHead2);
	}
	else if (hasCycle(pHead1) == true && hasCycle(pHead2) == true)
	{

	}
}
#endif

int main()
{
	/*
	ListNode* pHead = nullptr;

	PushBack(pHead, 1);
	PushBack(pHead, 2);
	PushBack(pHead, 3);

	PrintList(pHead);

	pHead = reverseList(pHead);
	PrintList(pHead);

	ListNode* p = FindMidNode(pHead);
	cout << p->_data << endl;

	p = FindLastKNode(pHead, 3);
	cout << p->_data << endl;
	
 */
	ListNode* p1 = nullptr;
	ListNode* p2 = nullptr;

	
	PushBack(p1, 1);
	PushBack(p1, 3);
	PushBack(p1, 5);
	PushBack(p1, 7);

	PushBack(p2, 2);
	PushBack(p2, 4);
	PushBack(p2, 6);
	PushBack(p2, 8);

	ListNode* result = MergeList(p1, p2);

	PrintList(result);


	return 0;
}
#endif


#include<functional>

#if 0

template<typename T,typename Compare>

void HeapAdjust(T* array, int size, int parent,Compare com)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && com(array[child + 1] , array[child]))
			child += 1;

		if (com(array[child] , array[parent]))
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

template<typename T,typename Compare>
void HeapSort(T* array, int size,Compare com)
{
	int root = ((size - 1 - 1) >> 1);
	for (root; root >= 0; --root)
	{
		HeapAdjust(array, size, root,com);
	}


	int end = size - 1;
	while (end != 0)
	{
		swap(array[0], array[end]);
		HeapAdjust(array, end, 0,com);
		end--;
	}
}

bool BinFind(int* array, int data, int size)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = (left + right) >> 1;

		if (data<array[mid])
		{
			right = mid - 1;
		}
		else if (data>array[mid])
		{
			left = mid + 1;
		}
		else
		{
			cout << data << " 存在!" << endl;
			return true;
		}
	}

	cout << data << " 不存在!" << endl;
	return false;
}
#endif

//写一个最小栈

//1.使用两个栈
//2.一次存两个值,一个正常插入的一个最小值
#include<stack>

class MinStack
{
public:
	MinStack()
	{}

	//使用方法二，一次存入两个元素
	void Push(int data)
	{
		//插入数据到s1中
		if(s.empty()==true)
		{
			s.push(data);
			s.push(data);
		}
		else
		{
			int a=s.top();
			s.pop();

			int Min=s.top();

			if(data<=Min)
			{
				s.push(a);

				s.push(data);
				s.push(data);
			}
			else
			{
				s.push(a);

				s.push(Min);
				s.push(data);
			}
			
		}
	}

	void Pop()
	{
		s.pop();
		s.pop();
	}

	int Top()
	{
		return s.top();
	}

	int GetMin()
	{
		int a=s.top();
		s.pop();

		int Min=s.top();
		s.push(a);

		return Min;
	}

	bool empty()
	{
		if(s.empty()==true)
		{
			return true;
		}
		return false;
	}

private:
	stack<int> s;
};

/*
int main()
{
	int array[]={3,4,1,9,0,6,8,5,2,7};

	int size=sizeof(array)/sizeof(array[0]);

	HeapSort(array,size,less<int>());

	for(auto e:array)
	{
		cout<<e<<" ";
	}
	cout<<endl;

	//BinFind(array,6,size);

	return 0;
}
*/

int main()
{
	MinStack ms;

	ms.Push(1);
	ms.Push(2);
	ms.Push(0);
	ms.Push(5);

	cout<<ms.GetMin()<<endl;
	cout<<ms.Top()<<endl;

	ms.Pop();
	cout<<ms.Top()<<endl;

	ms.Pop();
	ms.Pop();
	ms.Pop();

	if(ms.empty()==true)
	{
		cout<<"栈空"<<endl;
	}
	else
	{
		cout<<"栈非空"<<endl;
	}
	
	return 0;
}