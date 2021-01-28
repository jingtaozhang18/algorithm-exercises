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
        stack<TreeNode*> *a=new stack<TreeNode*>();
        stack<TreeNode*> *b=new stack<TreeNode*>();
        bool zx=true;
        vector<vector<int>> ans;
        if(!root) return ans;
        (*a).push(root);
        ans.push_back(vector<int>());
        while(!(*a).empty()){
            root=(*a).top();
            (*a).pop();
            ans[ans.size()-1].push_back(root->val);
            if(zx) {
                if(root->left) (*b).push(root->left);
                if(root->right) (*b).push(root->right);
            }else{
                if(root->right) (*b).push(root->right);
                if(root->left) (*b).push(root->left);
            }
            if((*a).empty()){
                swap(a,b);
                if((*a).size()) ans.push_back(vector<int>());
                zx=!zx;
            }
        }
        return ans;
    }
};