/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    vector<int> p;
    void dfs(TreeNode* root){
        if(root == nullptr)
            return;
        dfs(root->left);
        //cout<<root->val<<" ";
        p.push_back(root->val);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int temp = p[1]-p[0];
        for(int i = 2;i < p.size();i++){
            if(p[i] - p[i-1] <temp) temp =p[i] - p[i-1];
        }
        return temp;
    }
};
// @lc code=end

