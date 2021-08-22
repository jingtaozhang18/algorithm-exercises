// https://leetcode-cn.com/problems/legal-binary-search-tree-lcci/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool jgo(TreeNode* root, long long left, long long right)
    {
      if(!root) return true;
      if(root->val>left&&root->val<right) 
      {
        return jgo(root->left, left, root->val)&&jgo(root->right, root->val, right);
      }else
      {
        return false;
      }
    }
    bool isValidBST(TreeNode* root) {
      return jgo(root, LONG_MIN, LONG_MAX); // 错误点，边界问题，需要使用更大的边界
    }
};