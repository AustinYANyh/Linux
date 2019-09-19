#include "queue.h"
#include <iostream>
#include <assert.h>

using namespace std;

QNode* BuyNode(QueueData data)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));

	if (newnode == NULL)
	{
		assert(0);
	}

	newnode->data = data;
	newnode->_next = NULL;

	return newnode;
}

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
}

void QueuePush(Queue* q, QueueData data)
{
	assert(q);

	QNode* newnode = BuyNode(data);

	if (q->_front == NULL)
	{
		q->_front = q->_back = newnode;
	}
	else
	{
		q->_back->_next = newnode;
		q->_back = newnode;
	}
}

void QueuePop(Queue* q)
{
	//头部出队列,尾部插入
	assert(q);

	if (q->_front == NULL)
	{
		return;
	}

	QNode* newhead = q->_front;

	if (q->_front->_next == NULL)
	{
		q->_front = q->_back = NULL;
	}
	else
	{
		q->_front = newhead->_next;
		free(newhead);
		newhead = NULL;
	}
}

int QueueSize(Queue* q)
{
	assert(q);

	int count = 0;
	QNode* pCur = q->_front;

	while (pCur != NULL)
	{
		pCur = pCur->_next;
		count++;
	}

	return count;
}

QueueData QueueFront(Queue* q)
{
	if (q->_front == NULL)
	{
		return -1;
	}

	return q->_front->data;
}

QueueData QueueBack(Queue* q)
{
	if (q->_front == NULL)
	{
		return -1;
	}

	return q->_back->data;
}

void QueueDestory(Queue* q)
{
	assert(q);

	if(q->_front==NULL)
	{
		return;
	}

	QNode* pCur = q->_front;

	while (pCur != NULL)
	{
		q->_front = pCur->_next;
		free(pCur);

		//野指针置空
		pCur = NULL;
		pCur = q->_front;
	}

	q->_front = q->_back = NULL;
}

void printAll(Queue* q)
{
	assert(q);

	if (q->_front == NULL)
	{
		return;
	}

	QNode* pCur = q->_front;
	while (pCur != NULL)
	{
		cout << pCur->data << " " ;
		pCur = pCur->_next;
	}
}

void QueueTest()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);

	printAll(&q);
}

int main()
{
	QueueTest();

	system("pause");
}