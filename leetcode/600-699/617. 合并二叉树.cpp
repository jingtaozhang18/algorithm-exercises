// https://leetcode-cn.com/problems/merge-two-binary-trees/
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

class Solution {
 public:
  TreeNode* jcalc(TreeNode* ln, TreeNode* rn) {
    if (!ln && !rn) return nullptr;
    if (!ln) ln = rn, rn = nullptr;
    if (rn) ln->val += rn->val;
    ln->left = jcalc(ln->left, rn ? rn->left : nullptr);
    ln->right = jcalc(ln->right, rn ? rn->right : nullptr);
    return ln;
  }
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    return jcalc(root1, root2);
  }
};