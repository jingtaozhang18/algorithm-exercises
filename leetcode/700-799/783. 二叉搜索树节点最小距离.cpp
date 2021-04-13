// https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
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

// 无赖做法
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        set<int> st;
        while(que.size()){
            root=que.front();
            que.pop();
            if(root->left) que.push(root->left);
            if(root->right) que.push(root->right);
            st.insert(root->val);
        }
        auto p=st.begin();
        int ans=INT_MAX, pre=*p;
        for(++p;p!=st.end();++p){
            ans=min(ans, *p-pre), pre=*p;
        }
        return ans;
    }
};

// 非递归中序遍历
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> sta;
        int pre=-1, ans=INT_MAX;
        while(root||sta.size()){
            while(root) {sta.push(root); root=root->left;}
            root=sta.top(); sta.pop();
            if(pre==-1) pre=root->val;
            else ans=min(ans, root->val-pre), pre=root->val;
            root=root->right;
        }
        return ans;
    }
};