// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans;
      stack<TreeNode*> sta;
      while(root){
        ans.push_back(root->val);
        if(root->right) sta.push(root->right);
        if(root->left) root=root->left;
        else {if(sta.size()){root=sta.top(); sta.pop();} else root=nullptr;}
      }
      return ans;
    }
};