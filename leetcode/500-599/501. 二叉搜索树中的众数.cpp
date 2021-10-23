// https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<int> ans;
  int count = 0, base, maxCount = 0;
  void update(int x) {
    if (x == base) ++count;
    else {
      count = 1;
      base = x;
    }
    if (count == maxCount) {
      ans.push_back(base);
    }
    else if (count > maxCount) {
      ans.clear();
      ans.push_back(base);
      maxCount = count;
    }
  }
  void cenVist(TreeNode* root) {
    if (!root) return;
    cenVist(root->left);
    update(root->val);
    cenVist(root->right);
  }
  vector<int> findMode(TreeNode* root) {
    cenVist(root);
    return ans;
  }
};