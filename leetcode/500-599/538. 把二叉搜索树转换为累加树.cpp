// https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
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
  int acc = 0;
  void jcalc(TreeNode *root) {
    if (!root) return;
    jcalc(root->right);
    root->val = acc = root->val + acc;
    jcalc(root->left);
  }
  TreeNode *convertBST(TreeNode *root) {
    jcalc(root);
    return root;
  }
};
