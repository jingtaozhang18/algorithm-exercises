// https://leetcode-cn.com/problems/w6cpku/
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
  int calc(TreeNode *root, int acc) {
    if (!root) return acc;
    int right = calc(root->right, acc);
    root->val += right;
    int left = calc(root->left, root->val);
    return left;
  }
  TreeNode *convertBST(TreeNode *root) {
    calc(root, 0);
    return root;
  }
};