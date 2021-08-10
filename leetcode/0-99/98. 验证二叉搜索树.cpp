// https://leetcode-cn.com/problems/validate-binary-search-tree/
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
    bool judge(TreeNode* root, int vmin, int vmax){
        if(!root) return true;
        if(root->val<vmin||root->val>vmax) return false;
        if(root->val==INT_MIN){
            if(root->left) 
                return false;
            if(judge(root->right, root->val+1, vmax)==false) 
                return false;
        }else if(root->val==INT_MAX){
            if(root->right) 
                return false;
            if(judge(root->left, vmin, root->val-1)==false) 
                return false;
        }else{
            if(judge(root->right, root->val+1, vmax)==false) 
                return false;
            if(judge(root->left, vmin, root->val-1)==false) 
                return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return judge(root, INT_MIN, INT_MAX);
    }
};