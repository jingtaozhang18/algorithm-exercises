// https://leetcode-cn.com/problems/house-robber-iii/
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
    unordered_map<TreeNode*, int> ftou,tou; // 不偷，偷
    int jgo(TreeNode* root, bool t) {
        if(!root) return 0;
        if(t){
            auto p=tou.find(root);
            if(p!=tou.end()) return p->second;
            return tou[root]=root->val+jgo(root->left, false)+jgo(root->right, false);
        }else{
            auto p=ftou.find(root);
            if(p!=ftou.end()) return p->second;
            return ftou[root]=max(jgo(root->left, true), jgo(root->left, false))+max(jgo(root->right, true), jgo(root->right, false));
        }
    }
    int rob(TreeNode* root) {
        tou.clear(); ftou.clear();
        return max(jgo(root, true), jgo(root, false));
    }
};