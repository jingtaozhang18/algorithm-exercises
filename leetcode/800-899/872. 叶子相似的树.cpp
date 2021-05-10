// https://leetcode-cn.com/problems/leaf-similar-trees/
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
    vector<int> pre_visit(TreeNode* root){
        stack<TreeNode*> sta;
        vector<int> ans;
        while(root||sta.size()){
            while(root) {sta.push(root); root=root->left;}
            root=sta.top(); sta.pop();
            if(!root->right) {if(!root->left) ans.push_back(root->val); root=nullptr;}
            else root=root->right;
        }
        return ans;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a=move(pre_visit(root1));
        vector<int> b=move(pre_visit(root2));
        if(a.size()==b.size()){
            for(int i=0;i<a.size();++i){
                if(a[i]!=b[i]) return false;
            }
            return true;
        }
        return false;
    }
};