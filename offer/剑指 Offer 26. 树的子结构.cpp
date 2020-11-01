// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
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
    bool judge(TreeNode* a, TreeNode* b){
        if(!b) return true;
        if(!a) return false;
        if(a->val!=b->val) return false;
        return judge(a->left, b->left) && judge(a->right, b->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B) return false;
        return judge(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};