/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* node1 = new ListNode(0);
        ListNode* node2 = new ListNode(0);
        ListNode* cur1 = node1;
        ListNode* cur2 = node2;
        while (head)
        {
            if (head->val < x)
            {
                cur1->next = head;
                cur1 = cur1->next;
            }
            else
            {
                cur2->next = head;
                cur2 = cur2->next;
            }
            head = head->next;
        }

        cur2->next = NULL;
        cur1->next = node2->next;
        return node1->next;
    }
};
