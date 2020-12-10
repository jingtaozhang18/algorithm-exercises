// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* jgo(vector<int>& preorder, vector<int>& inorder, int pre_s, int pre_e, int in_s, int in_e) {
        if(pre_s>pre_e) return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_s]);
        int i;
        for(i=in_s;i<=in_e&&inorder[i]!=preorder[pre_s];++i);
        root->left = jgo(preorder, inorder, pre_s+1, pre_s+i-in_s, in_s, i-1);
        root->right = jgo(preorder, inorder, pre_s+i-in_s+1, pre_e, i+1, in_e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return jgo(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};