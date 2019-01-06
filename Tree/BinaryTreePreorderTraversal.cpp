/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        while (!stk.empty() || root)
        {
            if (root)
            {
                res.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            else
            {
                root = stk.top();
                root = root->right;
                stk.pop();
            }
        }
        return res;
    }
};
