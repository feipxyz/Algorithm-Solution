/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        // write your code here
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (n--)
        {
            p1 = p1->next;
        }

        if (p1 == NULL)
        {
            return head->next;
        }

        while (p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        p2->next = p2->next->next;
        return head;
    }
};
