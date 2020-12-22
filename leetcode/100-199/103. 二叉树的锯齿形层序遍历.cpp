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
        queue<TreeNode*> que;
        int nowl=1, nextl=0, level=0;
        vector<vector<int>> ans;
        vector<int> tmp;
        int i,j,t;
        if(!root) return ans;
        que.push(root);
        while(!que.empty()){
            TreeNode* nd=que.front(); que.pop();
            tmp.push_back(nd->val);
            if(nd->left) {que.push(nd->left); nextl++;}
            if(nd->right) {que.push(nd->right); nextl++;}
            if(!--nowl){ // 当前层处理完毕
                nowl=nextl, nextl=0;
                if(level%2) 
                    for(i=0,j=tmp.size()-1;i<j;++i,--j)
                        t=tmp[i],tmp[i]=tmp[j],tmp[j]=t;
                level++;
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};