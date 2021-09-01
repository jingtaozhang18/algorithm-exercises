// https://leetcode-cn.com/problems/pOCWxh/
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
  bool posV(TreeNode *root) {  // 无1
    if (!root) return false;
    bool left = posV(root->left);
    if (left == false) root->left = nullptr;
    bool right = posV(root->right);
    if (right == false) root->right = nullptr;
    if (left || right) {
      return true;
    }
    if (root->val == 0) return false;
    return true;
  }

  TreeNode *pruneTree(TreeNode *root) {
    if (posV(root))
      return root;
    else
      return nullptr;
  }
};