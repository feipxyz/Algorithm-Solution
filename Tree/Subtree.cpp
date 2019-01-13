/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param T1: The roots of binary tree T1.
     * @param T2: The roots of binary tree T2.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        // write your code here
        bool bSubTree = false;
        if (T2 == NULL)
        {
            bSubTree = true;
        }
        else if (T1 == NULL && T2 != NULL)
        {
            bSubTree = false;
        }
        else
        {
            if (T1->val == T2->val)
            {
                bSubTree = isSameTree(T1, T2);
            }

            if (!bSubTree)
            {
                bSubTree = isSubtree(T1->left, T2);
            }

            if (!bSubTree)
            {
                bSubTree = isSubtree(T1->right, T2);
            }
        }
        return bSubTree;
    }

    bool isSameTree(TreeNode* T1, TreeNode* T2)
    {
        bool bSame = false;
        if (T1 == NULL && T2 == NULL)
            bSame = true;
        else if ((T1 == NULL && T2 != NULL) || (T1 != NULL && T2 == NULL) || (T1->val != T2->val))
            bSame = false;
        else
            bSame = isSameTree(T1->left, T2->left) && isSameTree(T1->right, T2->right);

        return bSame;
    }
};
