class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		//ListNode* header;
		ListNode* header = new ListNode(0);
		header->next = NULL;
		ListNode* p = header;
        while(l1 != NULL && l2 != NULL)
		{
			if(l1->val > l2->val)
				p->next = l2,l2 = l2->next;
			else
				p->next = l1,l1 = l1->next;
			p = p->next;
		}
		if(l1 == NULL)
			p->next = l2;
		else if(l2 == NULL)
			p->next = l1;
		return header->next;
    }
};
