// https://leetcode-cn.com/problems/house-robber-iii/
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
    unordered_map<TreeNode*, int> mem;
    int jgo(TreeNode* root) {
        if(!root) return 0;
        auto p=mem.find(root);
        if(p!=mem.end()) return p->second;
        int ans = root->val;
        if(root->left) ans+=rob(root->left->left)+rob(root->left->right);
        if(root->right) ans+=rob(root->right->left)+rob(root->right->right);
        ans=max(rob(root->left)+rob(root->right), ans);
        mem[root]=ans;
        return ans;
    }
    int rob(TreeNode* root) {
        mem.clear();
        return jgo(root);
    }
};