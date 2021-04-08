// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> t;
        TreeNode *node;
        int nnow=1, nnext=0;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()){
            node=que.front();
            que.pop();
            t.push_back(node->val);
            if(node->left) {que.push(node->left); ++nnext;}
            if(node->right) {que.push(node->right); ++nnext;}
            if(--nnow==0){
                ans.push_back(t);
                t.clear();
                nnow=nnext, nnext=0;
            }
        }
        return ans;
    }
};