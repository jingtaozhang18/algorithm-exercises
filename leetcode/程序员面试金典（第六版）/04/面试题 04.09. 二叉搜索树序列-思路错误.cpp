// https://leetcode-cn.com/problems/bst-sequences-lcci/
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
    vector<vector<int>> jgo(vector<vector<int>> path, TreeNode* root){
      vector<vector<int>> ans;
      vector<vector<int>> tmp;
      if(root->left&&root->right){
        for(int i=0;i<path.size();++i) path[i].push_back(root->left->val);
        tmp=jgo(path, root->left);
        for(int i=0;i<tmp.size();++i) tmp[i].push_back(root->right->val);
        ans=jgo(tmp,root->right);
        for(int i=0;i<path.size();++i) path[i][path[i].size()-1]=root->right->val;
        tmp=jgo(path, root->right);
        for(int i=0;i<tmp.size();++i) tmp[i].push_back(root->left->val);
        for(auto e:jgo(tmp, root->left)) ans.push_back(e);
        return ans;
      }
      if(root->left){
        for(int i=0;i<path.size();++i) path[i].push_back(root->left->val);
        return path;
      }
      if(root->right){
        for(int i=0;i<path.size();++i) path[i].push_back(root->right->val);
        return path;
      }
      return path;
    }
    vector<vector<int>> BSTSequences(TreeNode* root) {
      vector<vector<int>> path{vector<int>{root->val}};
      return jgo(path, root);
    }
};