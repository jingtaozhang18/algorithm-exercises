// https://leetcode-cn.com/problems/3Etpl5/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
 public:
  int ans = 0;
  void dfs(TreeNode* root, int base) {
    if (!root) return;
    if (!root->left && !root->right) {
      ans += (base * 10 + root->val);
      return;
    }
    if (root->left) {
      dfs(root->left, base * 10 + root->val);
    }
    if (root->right) {
      dfs(root->right, base * 10 + root->val);
    }
  }
  int sumNumbers(TreeNode* root) {
    dfs(root, 0);
    return ans;
  }
};