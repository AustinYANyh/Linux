#include <stdio.h>
/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     struct ListNode *next;
 ** };
 **/
 
bool hasCycle(struct ListNode *head)
{
    if(head==NULL)
    {
	return NULL;
    }

    struct ListNode* pCur=head;
    struct ListNode* pPre=head;
    while(pCur!=NULL && pCur->next!=NULl)
    {
	pCur=pCur->next-next;
	pPre=pPre->next;
	if(pCur==pPre)
	{
	    return true;
	}
    }
    return false;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    //如果其中一条链表为空，肯定不会相交
    if(headA==NULL || headB==NULL)
    {
	return NULL;
    }

    int sizeA=1;
    int sizeB=1;
    struct ListNode * pA=headA;
    while(pA!=NULL)
    {
	sizeA++;
	pA=pA->next;
    }
    while(pB!=NULL)
    {
	sizeB++;
	pB=pB->ext;
    }

    //判断A和B链表的长短，长的先走差值步
    struct ListNode * ppA=headA;
    struct ListNode * ppB=headB;
    if(sizeA>sizeB)
    {
	for(sizeA;sizeA-sizeB!=0;sizeA--)
	{
	    ppA=ppA->next;
	}
    }
    if(sizeA<sizeB)
    {
	for(sizeB;sizeA-sizeB!=0;sizeB--)
	{
	    ppB=ppB->next;
	}
    }

    //长度相同时两个指针同时走
    while(ppA!=NULL)
    {
	ppA=ppA->next;
	ppB=ppB->next;
	if(ppA==ppB)
	{
	    return ppA;
	}
    }
    return NULL;
}
