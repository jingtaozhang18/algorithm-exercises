// https://leetcode-cn.com/problems/kTOapQ/
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

class BSTIterator {
 public:
  stack<TreeNode *> sta;
  TreeNode *root;
  BSTIterator(TreeNode *root) { this->root = root; }

  int next() {
    while (root) {
      sta.push(root);
      root = root->left;
    }
    root = sta.top();
    sta.pop();
    int ans = root->val;
    root = root->right;
    return ans;
  }

  bool hasNext() { return root || sta.size(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */