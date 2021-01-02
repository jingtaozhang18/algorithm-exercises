// https://leetcode-cn.com/problems/successor-lcci/
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
    bool flag=false;
    int tar;
    TreeNode* jgo(TreeNode*root){
      if(!root) return 0;
      TreeNode*ans=0;
      ans=jgo(root->left);
      if(ans) return ans;
      if(flag) return root;
      if(root->val==tar) flag=true;
      return jgo(root->right);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
      flag=false;
      tar=p->val;
      return jgo(root);
    }
};