// https://leetcode-cn.com/problems/WNC0Lk/
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
  vector<int> rightSideView(TreeNode *root) {
    if (!root) return {};
    queue<TreeNode *> que;
    int cur = 1, next = 0;
    que.push(root);
    vector<int> ans;
    while (que.size()) {
      root = que.front();
      que.pop();
      if (root->left) {
        que.push(root->left);
        ++next;
      }
      if (root->right) {
        que.push(root->right);
        ++next;
      }
      --cur;
      if (!cur) {
        ans.push_back(root->val);
        cur = next;
        next = 0;
      }
    }
    return ans;
  }
};