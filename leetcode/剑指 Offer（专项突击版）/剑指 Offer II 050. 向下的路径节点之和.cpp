// https://leetcode-cn.com/problems/6eUYwP/
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
  unordered_map<int, int> mp;
  int ans;
  int targetSum;
  void preVisit(TreeNode *root, int acc) {
    if (!root) return;
    acc += root->val;
    auto p = mp.find(acc - targetSum);
    if (p != mp.end()) {
      ans += p->second;
    }
    ++mp[acc];
    preVisit(root->left, acc);
    preVisit(root->right, acc);
    --mp[acc];
  }
  int pathSum(TreeNode *root, int targetSum) {
    ans = 0;
    this->targetSum = targetSum;
    mp[0]++;
    preVisit(root, 0);
    return ans;
  }
};