//https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
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
    int jgo(TreeNode* root){
        if(!root) return 0;
        else return max(jgo(root->left), jgo(root->right))+1;
    }
    int maxDepth(TreeNode* root) {
        return jgo(root);
    }
};