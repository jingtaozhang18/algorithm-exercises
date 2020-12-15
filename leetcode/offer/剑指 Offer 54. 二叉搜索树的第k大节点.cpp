// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
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
    void jgo(TreeNode* root, int& k, int& ans){
        if(root->right) jgo(root->right, k, ans);
        k--; if(!k) {ans=root->val; return;}
        if(root->left) jgo(root->left, k, ans);
    }
    int kthLargest(TreeNode* root, int k) {
        // root 一定存在
        int ans;
        jgo(root, k, ans);
        return ans;
    }
};