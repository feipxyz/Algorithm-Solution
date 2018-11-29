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
    struct cmp
    {
        bool operator() (ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, cmp> topQueue;
        for (auto a : lists)
        {
            if (a != NULL)
                topQueue.push(a);
        }

        ListNode* head = NULL;
        ListNode* tail;
        if (!topQueue.empty())
        {
            ListNode* node = topQueue.top();
            head = node;
            topQueue.pop();
            if (node->next)
            {
                topQueue.push(node->next);
            }
            tail = head;
        }

        while (!topQueue.empty())
        {
            ListNode* node = topQueue.top();
            topQueue.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next)
            {
                topQueue.push(node->next);
            }
        }

        return head;
    }
};
