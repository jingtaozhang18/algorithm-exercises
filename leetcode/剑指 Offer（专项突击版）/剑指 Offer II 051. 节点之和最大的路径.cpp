// https://leetcode-cn.com/problems/jC7MId/
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
  int ans = INT_MIN;
  int calc(TreeNode *root) {
    if (!root) return 0;
    int left = calc(root->left);
    int right = calc(root->right);
    ans = max(ans, left + right + root->val);
    return max(max(0, left + root->val), right + root->val);
  }
  int maxPathSum(TreeNode *root) {
    calc(root);
    return ans;
  }
};