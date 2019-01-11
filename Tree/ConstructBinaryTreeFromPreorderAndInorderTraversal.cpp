/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if (preorder.size() == 0)
            return NULL;

        TreeNode * root = new TreeNode(preorder[0]);
        int rootIndex = 0;
        while (inorder[rootIndex] != preorder[0]) {
            rootIndex++;
        }

        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
        vector<int> preorderRight(preorder.begin() + rootIndex + 1, preorder.end());
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> inorderRight(inorder.begin() + rootIndex + 1, inorder.end());

        root->left  = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);
        return root;
    }
};
