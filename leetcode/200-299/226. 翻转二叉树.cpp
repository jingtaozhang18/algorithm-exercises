// https://leetcode-cn.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

// 非递归
class Solution_1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            queue<TreeNode*> que;
            TreeNode *t;
            que.push(root);
            while(que.size()){
                t=que.front(); que.pop();
                swap(t->right, t->left);
                if(t->left) que.push(t->left);
                if(t->right) que.push(t->right);
            }
        }
        return root;
    }
};