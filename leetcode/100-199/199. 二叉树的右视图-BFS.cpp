//https://leetcode-cn.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        queue<TreeNode*> que;
        que.push(root);
        int now=1,next=0;
        TreeNode *t;
        vector<int> ans;
        while(!que.empty()){
            t=que.front(); que.pop();
            if(now--==1) ans.push_back(t->val);
            if(t->left) {que.push(t->left);next++;}
            if(t->right) {que.push(t->right);next++;}
            if(now==0) now=next, next=0;
        }
        return ans;
    }
};