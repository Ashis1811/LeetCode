/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int& length)
    {
        if(root == NULL) return 0;
        int left = helper(root->left, length);
        int right = helper(root->right, length);
        length = max(length, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int length = 0;
        helper(root, length);
        return length;
    }
};