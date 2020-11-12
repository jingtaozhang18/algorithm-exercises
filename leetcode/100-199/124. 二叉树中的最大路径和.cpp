// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
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
    int jgo(TreeNode *root, int& ans){
        int c=root->val,l=0,r=0,t;
        if(root->left) l=jgo(root->left, ans);
        if(root->right) r=jgo(root->right, ans);
        t=c+max(l, max(r, 0)); // 只能选择一条，作为父节点的一条路径看
        ans=max(ans, c+max(l,0)+max(r,0)); // 当作最后的结果看，联接两边
        return t;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        jgo(root, ans);
        return ans;
    }
};