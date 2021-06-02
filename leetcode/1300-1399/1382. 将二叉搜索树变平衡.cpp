// https://leetcode-cn.com/problems/balance-a-binary-search-tree/
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
    TreeNode* jgo(TreeNode* root){ // 进行左右子树的构造
        if(!root) return nullptr;
        TreeNode *fast=root, *slow=root;
        while(fast&&fast->right){
            fast=fast->right->right;
            slow=slow->right;
        }
        if(slow->left) {
            slow->left->right=nullptr;
            slow->left=nullptr;
            slow->left=jgo(root);
        }else{
            slow->left=nullptr;
        }
        if(slow->right){
            slow->right->left=nullptr;
            slow->right=jgo(slow->right);
        }else{
            slow->right=nullptr;
        }
        return slow;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return nullptr;
        // 将其变成链式的双向链表, 使用中序遍历
        TreeNode *head=nullptr, *t=nullptr;
        stack<TreeNode*> sta;
        while(root||sta.size()){
            while(root) {
                sta.push(root); 
                root=root->left;
            }
            root=sta.top(); sta.pop();
            if(!head) head=root;
            if(t) t->right=root;
            root->left=t;
            t=root;
            if(root->right) root=root->right;
            else root=nullptr;
        }
        // 取中点进行左右子树的构造
        return jgo(head);
    }
};