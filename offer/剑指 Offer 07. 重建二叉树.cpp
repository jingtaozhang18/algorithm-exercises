// https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
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
    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder, int index, int left, int right){
        if(left==right) return nullptr;
        TreeNode* t=new TreeNode(preorder[index]);
        if(right==left+1) return t;
        int i;
        for(i=left;i<right;++i)if(preorder[index]==inorder[i])break;
        t->left=buildNode(preorder, inorder, index+1,left, i);
        t->right=buildNode(preorder, inorder, index+1+i-left, i+1, right);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildNode(preorder, inorder, 0, 0, preorder.size());
    }
};