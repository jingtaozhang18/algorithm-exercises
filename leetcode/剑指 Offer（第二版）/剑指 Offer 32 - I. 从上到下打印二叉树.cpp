// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> ans;
        if(!root) return ans;
        que.push(root);
        TreeNode* t;
        while(!que.empty()){
            t=que.front();
            ans.push_back(t->val);
            if(t->left)que.push(t->left);
            if(t->right)que.push(t->right);
            que.pop();
        }
        return ans;
    }
};