// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> sta_a;
        stack<TreeNode*> sta_b;
        bool zx=true;
        vector<vector<int>> ans;
        if(!root) return ans;
        sta_a.push(root);
        ans.push_back(vector<int>());
        while(!sta_a.empty()){
            root=sta_a.top();
            sta_a.pop();
            ans[ans.size()-1].push_back(root->val);
            if(zx) {
                if(root->left) sta_b.push(root->left);
                if(root->right) sta_b.push(root->right);
            }else{
                if(root->right) sta_b.push(root->right);
                if(root->left) sta_b.push(root->left);
            }
            if(sta_a.empty()){
                sta_a=sta_b;
                while(sta_b.size()) sta_b.pop();
                if(sta_a.size()) ans.push_back(vector<int>());
                zx=!zx;
            }
        }
        return ans;
    }
};