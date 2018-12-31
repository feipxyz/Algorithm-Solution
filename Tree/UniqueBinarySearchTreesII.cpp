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
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) return {};
        return BackTracking(1, n);
    }

    vector<TreeNode*> BackTracking(int begin, int end)
    {
        vector<TreeNode*> tree;
        if (begin == end)
        {
            tree.push_back(new TreeNode(begin));
            return tree;
        }

        if (begin > end)
        {
            tree.push_back(NULL);
            return tree;
        }


        for (int i = begin; i <= end; i++)
        {
            vector<TreeNode*> LeftTrees = BackTracking(begin, i - 1);
            vector<TreeNode*> RightTrees = BackTracking(i + 1, end);

            for (auto ltree : LeftTrees)
            {
                for (auto rtree : RightTrees)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = ltree;
                    root->right = rtree;
                    tree.push_back(root);
                }
            }
        }
        return tree;
    }
};
