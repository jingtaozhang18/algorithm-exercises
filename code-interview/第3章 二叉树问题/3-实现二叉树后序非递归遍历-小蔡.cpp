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
    vector<int> postorderTraversal(TreeNode* node) {
        // 一个栈的做法
        vector<int> res;
        stack<TreeNode*> s;
        if(!node){
            return res;
        }
        s.push(node);   // node 代表最近一次弹出并放入res的节点
        TreeNode * top = nullptr; // top 代表当前栈顶节点
        while(!s.empty()){
            top = s.top();      
            // 如果top左、右孩子不等于node,也就是他们都没有入过栈，那么左孩子入栈
            if(top->left && node != top->left && node != top->right){
                s.push(top->left);
            // 如果top右孩子不等于node，也就是右孩子没有入过栈，那么入右孩子入栈
            }else if(top->right && node != top->right){ 
                s.push(top->right);
            // 当前节点的左右孩子都入栈过，那么当前节点就可以弹出并加入res
            }else{
                s.pop();
                res.push_back(top->val);
                node = top;
            }
        }
        return res;
        // 两个栈的做法
        // vector<int> res;
        // stack<TreeNode*> s, s2;
        // if(!root){
        //     return res;
        // }
        // s.push(root);
        // while(!s.empty()){
        //     TreeNode* one = s.top();
        //     s.pop();
        //     s2.push(one);
        //     if(one->left){
        //         s.push(one->left);
        //     }
        //     if(one->right){
        //         s.push(one->right);
        //     }
        // }
        // while(!s2.empty()){
        //     TreeNode* one = s2.top();
        //     s2.pop();
        //     res.push_back(one->val);
        // }
        // return res;
    }
};