// https://leetcode-cn.com/problems/first-common-ancestor-lcci/
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
    TreeNode *pp;
    TreeNode *qq;
    TreeNode *jgo(TreeNode* root){
      if(!root) return 0;
      bool flag=(root->val==pp->val)|(root->val==qq->val);
      TreeNode* a=jgo(root->left);
      if(flag && a) return root;
      TreeNode* b=jgo(root->right);
      if(flag && b) return root;
      if(flag||a&&b) return root;
      return a?a:b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      pp=p,qq=q;
      return jgo(root);
    }
};