// https://leetcode-cn.com/problems/path-sum-iii/
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
  int visit(TreeNode *root, int acc, int targetSum,
            unordered_map<int, int> &mp) {
    if (!root) return 0;
    acc += root->val;
    int sum = mp[acc - targetSum];
    // acc - x = targetSum
    ++mp[acc];
    sum += visit(root->left, acc, targetSum, mp);
    sum += visit(root->right, acc, targetSum, mp);
    --mp[acc];
    return sum;
  }
  int pathSum(TreeNode *root, int targetSum) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    return visit(root, 0, targetSum, mp);
  }
};