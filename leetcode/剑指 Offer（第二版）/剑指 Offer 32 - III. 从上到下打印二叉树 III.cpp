// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        int now=1,next=0,i,dir=1,level=0;
        TreeNode*t;
        queue<TreeNode*> que;
        que.push(root);
        ans.push_back(vector<int>(1));
        while(!que.empty()){
            t=que.front();que.pop();
            if(!now){now=next,next=0,dir*=-1,i=dir==1?0:now-1,level+=1;ans.push_back(vector<int>(now));}
            ans[level][i]=t->val,i+=dir;
            if(t->left) {que.push(t->left); next++;}
            if(t->right) {que.push(t->right); next++;}
            now--;
        }
        return ans;
    }
};