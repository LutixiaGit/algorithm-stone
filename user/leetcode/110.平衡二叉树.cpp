/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
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
    bool res = true;
    int dfs(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int depl = dfs(root->left);
        int depr = dfs(root->right);
        if(abs(depl - depr) > 1) res = false;
        return max(depl, depr) + 1;
    }
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
            return true;
        dfs(root);
        return res;
    }
};
// @lc code=end

