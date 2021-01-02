// https://leetcode-cn.com/problems/check-subtree-lcci/
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
    bool jgo(TreeNode* a, TreeNode *b){
      if(!a&&!b) return true;
      if(!a||!b) return false;
      if(a->val!=b->val) return false;
      return jgo(a->left, b->left) && jgo(a->right, b->right);
    }
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
      if(!t2) return true;
      if(!t1) return false;
      TreeNode *t;
      queue<TreeNode*> que;
      que.push(t1);
      while(!que.empty())
      {
        t=que.front();
        if(jgo(t, t2)) return true;
        que.pop();
        if(t->left) que.push(t->left);
        if(t->right) que.push(t->right);
      }
      return false;
    }
};