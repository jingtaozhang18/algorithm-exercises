// https://leetcode-cn.com/problems/NYBBNL/
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
  TreeNode *increasingBST(TreeNode *root) {
    stack<TreeNode *> sta;
    TreeNode *head = nullptr, *pre = nullptr;
    while (sta.size() || root) {
      while (root) {
        sta.push(root);
        root = root->left;
      }
      root = sta.top();
      sta.pop();
      if (!head) head = root;
      if (pre) pre->right = root;
      root->left = nullptr;
      pre = root;
      root = root->right;
    }
    return head;
  }
};