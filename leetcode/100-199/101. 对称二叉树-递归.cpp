// https://leetcode-cn.com/problems/symmetric-tree/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool jcalc(TreeNode* left, TreeNode *right){
        if(!left&&!right) return true;
        if(!left||!right) return false;
        if(left->val!=right->val) return false;
        return jcalc(left->left, right->right)&&jcalc(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return jcalc(root, root);
    }
};