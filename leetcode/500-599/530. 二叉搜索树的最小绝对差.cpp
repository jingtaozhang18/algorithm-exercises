// https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
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
    int pre=-1, ans=INT_MAX;
    void jgo(TreeNode* root){
        if(root->left) jgo(root->left);
        if(pre==-1) pre=root->val;
        else ans=min(ans, root->val-pre), pre=root->val;
        if(root->right) jgo(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        jgo(root);
        return ans;
    }
};