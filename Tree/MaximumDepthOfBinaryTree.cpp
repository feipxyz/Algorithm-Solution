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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int res = 0;
        queue<TreeNode*> qTree;
        qTree.push(root);
        while (!qTree.empty())
        {
            res++;
            for (int i = 0, n = qTree.size(); i < n; i++)
            {
                TreeNode* tmp = qTree.front();
                qTree.pop();
                if (tmp->left)
                    qTree.push(tmp->left);
                if (tmp->right)
                    qTree.push(tmp->right);
            }
        }
        return res;
    }
};
