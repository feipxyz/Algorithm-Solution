/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 循环解法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<TreeNode*> qTree;
        qTree.push(root->left);
        qTree.push(root->right);

        while (!qTree.empty())
        {
            TreeNode* ltr = qTree.front();
            qTree.pop();
            TreeNode* rtr = qTree.front();
            qTree.pop();

            if (ltr == NULL && rtr == NULL)
                continue;

            if ((ltr != NULL && rtr == NULL) || (ltr == NULL && rtr != NULL)
                || (ltr->val != rtr->val))
                return false;
            qTree.push(ltr->left);
            qTree.push(rtr->right);
            qTree.push(ltr->right);
            qTree.push(rtr->left);
        }
        return true;
    }
};

// 递归解法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* leftSub, TreeNode* rightSub)
    {
        if (leftSub == NULL && rightSub == NULL)
            return true;

        if ((leftSub == NULL && rightSub != NULL) || (leftSub != NULL && rightSub == NULL)
            || (leftSub->val != rightSub->val))
            return false;

        return helper(leftSub->left, rightSub->right) && helper(leftSub->right, rightSub->left);
    }
};
