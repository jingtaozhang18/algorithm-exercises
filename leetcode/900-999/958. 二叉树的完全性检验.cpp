// https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/
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
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> que;
    que.push(root);
    bool flag = true;
    while (que.size()) {
      root = que.front();
      que.pop();
      if (root->left) {
        if (flag) que.push(root->left);
        else return false;
      }
      else {
        flag = false;
      }
      if (root->right) {
        if (flag) que.push(root->right);
        else return false;
      }
      else {
        flag = false;
      }
    }
    return true;
  }
};