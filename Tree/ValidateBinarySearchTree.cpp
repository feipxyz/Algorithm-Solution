/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 第一种解法：递归
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, NULL, NULL);
    }

    bool valid(TreeNode* root, TreeNode* minnode, TreeNode* maxnode)
    {
        if (root == NULL) return true;
        if ((minnode && root->val <= minnode->val) || (maxnode && root->val >= maxnode->val))
            return false;

        return valid(root->left, minnode, root) && valid(root->right, root, maxnode);
    }
};

// 第二种解法：迭代
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        if (!root) return true;
        TreeNode* pre = NULL;
        while (root || !stk.empty())
        {
            while (root)
            {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            if (pre && pre->val >= root->val)
                return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};
