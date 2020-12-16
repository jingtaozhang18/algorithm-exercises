// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从后序遍历的框架中实现
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        TreeNode *lc = lowestCommonAncestor(root->left, p, q);
        TreeNode *rc = lowestCommonAncestor(root->right, p, q);
        if(root->val==p->val||root->val==q->val||(lc&&rc)) return root;
        return lc?lc:rc;
    }
};