// https://leetcode-cn.com/problems/symmetric-tree/
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
  bool jcalc(TreeNode *left, TreeNode *right) {
    queue<TreeNode *> qa, qb;
    qa.push(left);
    qb.push(right);
    while (qa.size()) {
      left = qa.front();
      qa.pop();
      right = qb.front();
      qb.pop();
      if (left || right) {
        if (!left || !right)
          return false;
        else {
          if (left->val != right->val) return false;
          qa.push(left->left);
          qb.push(right->right);
          qa.push(left->right);
          qb.push(right->left);
        }
      }
    }
    return true;
  }
  bool isSymmetric(TreeNode *root) { return jcalc(root, root); }
};