// https://leetcode-cn.com/problems/increasing-order-search-tree/
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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> sta;
        TreeNode *head=nullptr, *pre=nullptr;
        while(sta.size()||root){
            while(root) {sta.push(root); root=root->left;}
            root=sta.top(); sta.pop();
            if(!head) {
                pre=head=root;
            }else{
                pre->right=root;
                root->left=nullptr;
                pre=root;
            }
            if(root->right) root=root->right;
            else root=nullptr;
        }
        return head;
    }
};