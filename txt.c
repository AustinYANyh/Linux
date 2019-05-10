/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 ** int val;
 ** struct ListNode *next;
 ** };
 **/
 *}

 bool hasCycle(struct ListNode *head)
{
    if(head==NULL)
    {
	return NULL;
    }
    struct ListNode *pFast=head;
    struct ListNode *pSlow=head;
    while(pFast!=NULL && pFast->next!=NULL)
    {
	pFast=pFast->next->next;
	pSlow=pSlow->next;

	 if(pFast==pSlow)
	 {
	    return true;
	 }
    }
    return false;   
}
