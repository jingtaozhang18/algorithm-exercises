// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        vector<int> ans;
        while(root||sta.size()){
            while(root){sta.push(root); root=root->left;}
            root=sta.top(); sta.pop();
            ans.push_back(root->val);
            if(root->right) root=root->right;
            else root=nullptr;
        }
        return ans;
    }
};