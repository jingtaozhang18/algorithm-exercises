// https://leetcode-cn.com/problems/balanced-binary-tree/
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
    bool ans;
    int jgo(TreeNode* root){
        if(!root) return 0;
        int left=0, right=0;
        if(ans) left=jgo(root->left);
        if(ans) right=jgo(root->right);
        if(abs(left-right)>1) ans=false;
        return max(left, right)+1;
    }
    bool isBalanced(TreeNode* root) {
        ans=true;
        jgo(root);
        return ans;
    }
};