// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
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
    int ans;
    void jgo(TreeNode* root, int level){
        if(!root->left&&!root->right) {ans=min(ans, level); return;} // 叶子节点的定义
        if(level>=ans) return; // 没有继续探索的必要了
        if(root->left) jgo(root->left, level+1);
        if(root->right) jgo(root->right, level+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        ans=INT_MAX;
        jgo(root, 1);
        return ans;
    }
};