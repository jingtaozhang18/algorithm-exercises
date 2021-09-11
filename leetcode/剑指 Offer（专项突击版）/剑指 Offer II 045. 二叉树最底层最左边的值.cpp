// https://leetcode-cn.com/problems/LwUNpT/
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
  TreeNode *ans = nullptr;
  int max_deep = 0;
  void preVist(TreeNode *root, int deep) {
    if (!root) return;
    if (deep > max_deep) {
      max_deep = deep;
      ans = root;
    }
    preVist(root->left, deep + 1);
    preVist(root->right, deep + 1);
  }
  int findBottomLeftValue(TreeNode *root) {
    preVist(root, 1);
    return ans->val;
  }
};