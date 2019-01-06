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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* last = NULL;
        while (!stk.empty() || root)
        {
            if (root)
            {
                stk.push(root);
                root = root->left;
            }
            else
            {
                TreeNode* node = stk.top();
                if (node->right && node->right != last)
                {
                    root = node->right;
                }
                else
                {
                    res.push_back(node->val);
                    last = node;
                    stk.pop();
                }
            }
        }
        return res;
    }
};
