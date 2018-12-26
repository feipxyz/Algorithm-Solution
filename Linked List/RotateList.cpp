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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;

        ListNode* tail = head;
        int len = 1;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k % len;

        for (auto i = 0; i < len - k; i++)
        {
            tail = tail->next;
        }
        ListNode* newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};
