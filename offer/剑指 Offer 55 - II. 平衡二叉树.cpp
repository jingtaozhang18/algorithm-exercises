//https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
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
    int jgo(TreeNode* root, bool& ans){
        if(!root) return 0;
        int l=jgo(root->left, ans), r=jgo(root->right, ans);
        if(abs(l-r)>1) ans=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        jgo(root, ans);
        return ans;
    }
};