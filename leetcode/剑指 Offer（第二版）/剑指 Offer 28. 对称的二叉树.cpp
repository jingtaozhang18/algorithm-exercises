// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
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
    bool judge(TreeNode* a, TreeNode* b){
        if(!a&&!b) return true;
        if(!a||!b) return false;
        if(a->val!=b->val) return false;
        return judge(a->left, b->right) && judge(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return judge(root->left, root->right);
    }
};