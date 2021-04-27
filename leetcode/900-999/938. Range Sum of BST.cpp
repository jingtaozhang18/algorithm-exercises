// https://leetcode-cn.com/problems/range-sum-of-bst/
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        stack<TreeNode*> sta;
        while(sta.size()||root){
            while(root) {
                sta.push(root);
                if(root->val<low) root=nullptr;
                else root=root->left;
            }
            root=sta.top(); sta.pop();
            if(root->val>=low&&root->val<=high) ans+=root->val;
            if(root->val>high) root=nullptr;
            else root=root->right;
        }
        return ans;
    }
};