// 给一个二叉树，返回树中最长路径的跳转数
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

int calc(node* root, int& ans){
    if(!root) return 0;
    int left=calc(root->left, ans);
    int right=calc(root->right, ans);
    ans=max(ans, left+right);
    return max(left, right)+1;
}

int entry(node* root){
    int ans=0;
    calc(root, ans);
    return ans;
}
