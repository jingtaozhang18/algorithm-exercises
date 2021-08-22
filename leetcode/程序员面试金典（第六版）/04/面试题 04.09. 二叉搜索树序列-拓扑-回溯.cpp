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
    vector<vector<int>> ans;
    void jgo(vector<int> path, set<TreeNode*> arr){
      if(arr.size()==0) ans.push_back(path);
      int size=path.size();
      path.push_back(0);
      for(auto e: arr){
        path[size]=e->val;
        set<TreeNode*> st(arr);
        st.erase(st.find(e));
        if(e->left) st.insert(e->left);
        if(e->right) st.insert(e->right);
        jgo(path, st);
      }
    }
    vector<vector<int>> BSTSequences(TreeNode* root) {
      ans.clear();
      set<TreeNode*> st;
      if(root) st.insert(root);
      jgo(vector<int>(), st);
      return ans;
    }
};