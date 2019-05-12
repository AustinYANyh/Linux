/*
 *// Definition for a Node.
class Node {
    public:
    int val;
    Node* next;
    Node* random;
}    
};
*
class Solution {
    public:
	{
	    Node* BuyNode(int val)
	    {
		Node* newnode=(Node*)malloc(sizeof(Node));
		if(newnode==NULL)
		{
		    assert(0);
		}
		newnode->val=val;
		newnode->next=NULL;
		newnode->random=NULL;
		return newnode;
	    }

	    Node* copyRandomList(Node* head)
	    {
		//如果链表为空,拷贝不了
		if(head==NULL)
		{
		    return NULL;
	        }

		//在每个节点后插入一个新节点
		Node* p1=head;
		while(p1->next!=NULL)
		{
		    Node* node=BuyNode(p1->val);
		    node->next=p1->next;
		    p1->next=node;
		    p1=node->next;
		    node=p1->next;
		}
		Node* node=BuyNode(p1->val);
		p1->next=node;
		node->next=NULL;

		//给新插入的随机指针域赋值
		p1=head;
		Node* p2=head->next;
		Node* phead=p2;
		while(p1!=NULL)
		{
		    if(p1->random!=NULL)
		    {
			p2=p1->next;
			p2->random=p1->random->next;
			p1=p2->next;
		    }
		    else 
		    {
			p2=p1->next;
			p2->random=NULL;
			p1=p2->next;
		    }
		    
		 }

		//将新插入的节点从原链表中拆除
		p1=head;
		p2=head->next;
		while(p1->next!=NULL)
		{
		    p1->next=p2->next;
		    p1=p2;
		    p2=p1->next;
		} 
		return phead;
	     }
}
