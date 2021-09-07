// https://leetcode-cn.com/problems/P5rCT8/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    bool flag = false;
    stack<TreeNode*> sta;
    while (sta.size() || root) {
      while (root) {
        sta.push(root);
        root = root->left;
      }
      root = sta.top();
      sta.pop();
      if (flag) return root;
      if (root == p) flag = true;
      root = root->right;
    }
    return nullptr;
  }
};