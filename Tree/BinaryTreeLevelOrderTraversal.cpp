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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        queue<TreeNode*> qNodes;
        vector<int> cur;
        qNodes.push(root);
        qNodes.push(NULL);

        while (!qNodes.empty())
        {
            TreeNode* tmp = qNodes.front();
            qNodes.pop();
            if (tmp == NULL)
            {
                res.push_back(cur);
                cur.resize(0);
                if (qNodes.size() > 0)
                    qNodes.push(NULL);
            }
            else
            {
                cur.push_back(tmp->val);
                if (tmp->left)
                    qNodes.push(tmp->left);
                if (tmp->right)
                    qNodes.push(tmp->right);
            }
        }
        return res;
    }
};
