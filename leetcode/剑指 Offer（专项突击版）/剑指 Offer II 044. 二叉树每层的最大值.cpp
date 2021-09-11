// https://leetcode-cn.com/problems/hPov7L/
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
  vector<int> largestValues(TreeNode *root) {
    if (!root) return {};
    queue<TreeNode *> que;
    vector<int> ans;
    que.push(root);
    int n_cur = 1, n_next = 0, x = INT_MIN;
    while (que.size()) {
      root = que.front();
      que.pop();
      --n_cur;
      x = max(x, root->val);
      if (root->left) {
        n_next++;
        que.push(root->left);
      }
      if (root->right) {
        n_next++;
        que.push(root->right);
      }
      if (n_cur == 0) {
        ans.push_back(x);
        n_cur = n_next;
        n_next = 0;
        x = INT_MIN;
      }
    }
    return ans;
  }
};