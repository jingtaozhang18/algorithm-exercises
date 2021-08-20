// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  void flatten(TreeNode *root) {
    // 先序遍历
    stack<TreeNode *> sta;
    TreeNode *pre = nullptr, *ans = root;
    bool flag;
    while (root || sta.size()) {
      flag = root; // 判断root会不会是个最左孩子
      while (root) {
        sta.push(root);
        root = root->left;
      }
      root = sta.top();
      sta.pop();
      if (flag) pre = root;
      if (root->right) {
        pre->left = root->right;
        root = root->right;
      }
      else
        root = nullptr;
    }
    root = ans;
    while (root) {
      root->right = root->left;
      root->left = nullptr;
      root = root->right;
    }

    root = ans;
  }
};