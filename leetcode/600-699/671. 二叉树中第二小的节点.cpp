// https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/
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
    void posVisit(TreeNode* root, int base, int& ans){
        if(!root) return;
        if(root->val>base){ // 无需继续向下
            if(ans==-1) ans=root->val;
            else ans=min(ans, root->val);
        }else{
            posVisit(root->left, base, ans);
            posVisit(root->right, base, ans);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        int base=root->val, ans=-1;
        posVisit(root, base, ans);
        return ans;
    }
};
