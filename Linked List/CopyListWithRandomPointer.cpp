/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// 第一种方法，时间复杂度O(n2)
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* cur = dummy;
        RandomListNode* p = head;
        // 第一次建立正常的链表
        while (p)
        {
            RandomListNode* tmp = new RandomListNode(p->label);
            cur->next = tmp;
            cur = cur->next;
            p = p->next;
        }

        p = head;
        cur = dummy->next;
        // 第二次循环寻找随机指向的节点
        while (p)
        {
            if (p->random != NULL)
            {
                RandomListNode* srcPos = head;
                RandomListNode* findPos = dummy->next;
                // 每次寻找从头开始
                while (srcPos != p->random)
                {
                    srcPos = srcPos->next;
                    findPos = findPos->next;
                }
                cur->random = findPos;
            }

            p = p->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};


// 第二种方法，以空间换时间，O(n)的空间，O(n)的时间
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* cur = dummy;
        RandomListNode* p = head;

        map<RandomListNode*, RandomListNode*> mpSrcToTag;

        // 建立链表
        while (p)
        {
            RandomListNode* tmp = new RandomListNode(p->label);
            cur->next = tmp;
            mpSrcToTag[p] = tmp;
            cur = cur->next;
            p = p->next;
        }

        p = head;
        while (p)
        {
            if (p->random)
            {
                mpSrcToTag[p]->random = mpSrcToTag[p->random];
            }
            p = p->next;
        }

        return dummy->next;
    }
};

// 第三种方法，O(1)的空间，O(n)的时间
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        CloneList(head);
        ConnectList(head);
        return SplitList(head);
    }

    void CloneList(RandomListNode* head)
    {
        RandomListNode* p = head;

        while (p)
        {
            RandomListNode* newNode = new RandomListNode(p->label);
            RandomListNode* tmp = p->next;
            p->next = newNode;
            newNode->next = tmp;
            p = tmp;
        }
    }

    void ConnectList(RandomListNode* head)
    {
        RandomListNode* p = head;
        while (p)
        {
            if (p->random)
            {
                p->next->random = p->random->next;
            }
            p = p->next;
            p = p->next;
        }
    }

    RandomListNode* SplitList(RandomListNode* head)
    {
        if (head == NULL)
            return NULL;

        RandomListNode* p = head->next;
        while (p)
        {
            if (p->next)
            {
                p->next = p->next->next;
            }
            p = p->next;
        }
        return head->next;
    }
};
