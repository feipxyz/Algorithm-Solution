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
        stack<TreeNode*> stackNode;
        vector<int> result;
        TreeNode* p = root;
        TreeNode* last = NULL;
        while (p != NULL || !stackNode.empty())
        {
            if (p != NULL)
            {
                stackNode.push(p);
                p = p->left;
            }
            else
            {
                TreeNode* tmp = stackNode.top();
                if (tmp->right && tmp->right != last)
                {
                    p = tmp->right;
                }
                else
                {
                    stackNode.pop();
                    last = tmp;
                    result.push_back(tmp->val);
                }
            }
        }
        return result;
    }
};
