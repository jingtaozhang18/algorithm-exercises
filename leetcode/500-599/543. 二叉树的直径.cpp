// https://leetcode-cn.com/problems/diameter-of-binary-tree/
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
  int ans;
  int jcalc(TreeNode *root) {
    if (!root) return 0;
    int ln = jcalc(root->left);
    int rn = jcalc(root->right);
    ans = max(ans, ln + rn);
    return max(ln, rn) + 1;
  }
  int diameterOfBinaryTree(TreeNode *root) {
    ans = 0;
    jcalc(root);
    return ans;
  }
};