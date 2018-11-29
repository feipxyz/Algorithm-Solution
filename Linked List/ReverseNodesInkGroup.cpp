/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//递归解决方案
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int count = 0;
        while (cur != NULL && count != k)
        {
            cur = cur->next;
            count++;
        }

        if (count == k)
        {
            cur = reverseKGroup(cur, k);
            while (k--)
            {
                ListNode* tmp = head->next;
                head->next = cur;
                cur = head;
                head = tmp;
            }

            head = cur;
        }

        return head;
    }
};

class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        int num = 0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* cur = dummy;
        ListNode* pre = dummy;
        ListNode* nex;
        while (cur = cur->next)
            num++;

        while (num >= k)
        {
            cur = pre->next;
            nex = cur->next;

            for (int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};
