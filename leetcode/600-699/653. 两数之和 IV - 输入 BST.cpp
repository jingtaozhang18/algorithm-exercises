// https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

struct cl {
  stack<TreeNode*> sta;
  TreeNode* root;
  cl(TreeNode* root) : root(root){};
  TreeNode* next() {
    TreeNode* ans;
    if (!root && sta.empty()) return nullptr;
    while (root) {
      sta.push(root);
      root = root->left;
    }
    root = sta.top();
    sta.pop();
    ans = root;
    root = root->right;
    return ans;
  }
};

struct cr {
  stack<TreeNode*> sta;
  TreeNode* root;
  cr(TreeNode* root) : root(root){};
  TreeNode* next() {
    TreeNode* ans;
    if (!root && sta.empty()) return nullptr;
    while (root) {
      sta.push(root);
      root = root->right;
    }
    root = sta.top();
    sta.pop();
    ans = root;
    root = root->left;
    return ans;
  }
};

class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    cl l(root);
    cr r(root);
    TreeNode *left = l.next(), *right = r.next();
    while (left && right && left != right) {
      if (left->val + right->val == k)
        return true;
      else if (left->val + right->val < k)
        left = l.next();
      else
        right = r.next();
    }
    return false;
  }
};