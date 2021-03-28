// https://leetcode-cn.com/problems/binary-search-tree-iterator/
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

class BSTIterator {
public:
    stack<TreeNode*> sta;
    BSTIterator(TreeNode* root) {
        while(root) {sta.push(root); root=root->left;}
    }
    
    int next() {
        TreeNode *it = sta.top();
        sta.pop();
        if(it->right){
            TreeNode *root=it->right;
            while(root) {sta.push(root); root=root->left;}
        }
        return it->val;
    }
    
    bool hasNext() {
        return sta.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */