// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
        queue<TreeNode*> que;
        int next=0,now=1,level=0;
        TreeNode*t;
        que.push(root);
        ans.push_back(vector<int>());
        while(!que.empty()){
            t=que.front();
            que.pop();
            if(!now){now=next,next=0,level++;ans.push_back(vector<int>());}
            ans[level].push_back(t->val);
            if(t->left) {next++;que.push(t->left);}
            if(t->right) {next++;que.push(t->right);}
            now--;
        }
        return ans;
    }
};