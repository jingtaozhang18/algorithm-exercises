// https://leetcode-cn.com/problems/minimum-height-tree-lcci/
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
    TreeNode* jgo(vector<int>& nums, int left, int right)
    {
      if(left>right) return nullptr;
      int center=left+(right-left)/2;
      TreeNode *root=new TreeNode(nums[center]);
      root->left=jgo(nums, left, center-1);
      root->right=jgo(nums, center+1, right);
      return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return jgo(nums, 0, nums.size()-1);
    }
};