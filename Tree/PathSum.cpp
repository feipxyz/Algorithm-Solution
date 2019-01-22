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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
        {
            return false;
        }

        return Find(root, sum);
    }

    bool Find(TreeNode* root, int sum) {

        sum = sum - root->val;
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == 0)
                return true;
            else
                return false;
        }

        bool bFind = false;
        if (root->left)
        {
            bFind = Find(root->left, sum);
        }

        if (!bFind && root->right)
        {
            bFind = Find(root->right, sum);
        }
        return bFind;
    }

};
