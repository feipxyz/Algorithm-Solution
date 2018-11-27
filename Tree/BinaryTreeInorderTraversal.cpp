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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stackNode;
        vector<int> result;
        while (!stackNode.empty() || root != NULL)
        {
            if (root != NULL)
            {
                stackNode.push(root);
                root = root->left;
            }
            else
            {
                TreeNode* tmp = stackNode.top();
                stackNode.pop();
                result.push_back(tmp->val);
                root = tmp->right;
            }

        }
        return result;
    }
};
