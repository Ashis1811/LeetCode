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
    pair<int, TreeNode*> dfs(TreeNode* root) //{depth, LCA}
    {
        if(! root) return {0, NULL};
        auto [leftDepth, lelftLCA] = dfs(root->left);
        auto [rightDepth, rightLCA] = dfs(root->right);
        if(leftDepth > rightDepth) return {leftDepth + 1, lelftLCA};
        else if(leftDepth < rightDepth) return {rightDepth + 1, rightLCA};
        else return {leftDepth + 1, root};

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};