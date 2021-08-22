// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void jgo(TreeNode*root, int sum, int acc, vector<int>&path, vector<vector<int>>& ans){
        if(!root) return;
        acc+=root->val;
        path.push_back(root->val);
        if(acc==sum&&!root->left&&!root->right) ans.push_back(path);
        if(root->left)jgo(root->left, sum, acc, path, ans);
        if(root->right)jgo(root->right, sum, acc, path, ans);
        path.pop_back();
        acc-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        jgo(root, sum, 0, path, ans);
        return ans;
    }
};