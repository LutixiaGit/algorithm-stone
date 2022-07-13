/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool has(TreeNode* root, int targetSum){
        if(root->left == nullptr && root->right == nullptr)
            return targetSum == root->val;
        targetSum-=root->val;
        bool res = false;
        if(root->left != nullptr)
            res |= has(root->left,targetSum);
        if(root->right != nullptr)
            res |= has(root->right,targetSum);
        return res;
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == nullptr)
            return false;
        return has(root,targetSum);

    }

       
};
// @lc code=end

