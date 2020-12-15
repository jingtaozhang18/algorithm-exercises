// https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
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
    void mirror(TreeNode* root){
        if(!root) return;
        TreeNode* t;
        t=root->left, root->left=root->right, root->right=t;
        mirror(root->left);
        mirror(root->right);
    }
    TreeNode* mirrorTree(TreeNode* root) {
        mirror(root);
        return root;
    }
};