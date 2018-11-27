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
        stack<TreeNode*> stackNode;
        vector<int> result;
        while (!stackNode.empty() || root != NULL)
        {
            if (root != NULL)
            {
                result.push_back(root->val);
                stackNode.push(root);
                root = root->left;
            }
            else
            {
                TreeNode* tmp = stackNode.top();
                stackNode.pop();
                root = tmp->right;
            }
        }

        return result;
    }
};
