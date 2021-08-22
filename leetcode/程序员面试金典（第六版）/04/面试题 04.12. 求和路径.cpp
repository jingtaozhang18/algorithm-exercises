// https://leetcode-cn.com/problems/paths-with-sum-lcci/
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
    int ans;
    int tar;
    void jgo(int acc, TreeNode* start, TreeNode* root){
        acc+=root->val;
        // cout<<start->val<<"\t"<<root->val<<endl;
        if(acc==tar) ans++;
        if(root->left) {
            jgo(acc, start, root->left); 
            // jgo(0, root->left, root->left);
        }
        if(root->right) {
            jgo(acc, start, root->right); 
            // jgo(0, root->right, root->right); // 错误点，不能从这里嵌套新的开始
        }
    }
    int pathSum(TreeNode* root, int sum) {
        ans=0, tar=sum;
        if(!root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* root=que.front();
            que.pop();
            jgo(0, root, root);
            if(root->left) que.push(root->left);
            if(root->right) que.push(root->right);
        }
        return ans;
    }
};