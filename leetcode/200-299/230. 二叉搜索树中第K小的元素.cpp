// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
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
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> sta;
    while (sta.size() || root) {
      while (root) {
        sta.push(root);
        root = root->left;
      }
      root = sta.top();
      sta.pop();
      if (--k == 0) {
        return root->val;
      }
      if (root->right)
        root = root->right;
      else
        root = nullptr;
    }
    return -1;
  }
};