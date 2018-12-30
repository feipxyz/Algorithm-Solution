/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 解法一：迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = head->next;

        while (next != NULL)
        {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre;
        return cur;
    }
};

// 解法二：递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* tmp = head->next;
        ListNode* rnode = reverseList(head->next);
        tmp->next = head;
        head->next = NULL;
        return rnode;
    }
};
