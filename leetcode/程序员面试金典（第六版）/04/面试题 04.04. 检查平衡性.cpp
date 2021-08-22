// https://leetcode-cn.com/problems/check-balance-lcci/
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
    bool flag=true;
    int jgo(TreeNode* root){
        if(!root) return 0;
        int l=jgo(root->left);
        int r=jgo(root->right);
        if(abs(l-r)>1) flag=false;
        return max(l, r)+1;
    }
    bool isBalanced(TreeNode* root) {
        flag=true;
        jgo(root);
        return flag;
    }
};