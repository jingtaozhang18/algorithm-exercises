// https://leetcode-cn.com/problems/cousins-in-binary-tree/
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
    int deepa, deepb;
    TreeNode *roota, *rootb;
    void jgo(TreeNode* root, int deep, TreeNode* father, int x, int y){
        if(root->val==x) deepa=deep, roota=father;
        if(root->val==y) deepb=deep, rootb=father;
        if(root->left) jgo(root->left, deep+1, root, x, y);
        if(root->right) jgo(root->right, deep+1, root, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root) jgo(root, 0, nullptr, x, y);
        return deepa==deepb&&roota!=rootb;
    }
};