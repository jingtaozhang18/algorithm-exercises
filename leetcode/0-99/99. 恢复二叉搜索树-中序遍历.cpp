// https://leetcode-cn.com/problems/recover-binary-search-tree/
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
    TreeNode *ferror, *lerror, *prenode; // 第一个和最后一个的错误节点
    int pre;
    void jgo(TreeNode* root){
        if(!root) return;
        jgo(root->left);
        if(prenode&&pre>root->val){ // 出现错误的节点
            if(!ferror) ferror=prenode, lerror=root;
            else lerror=root;
        }
        pre=root->val, prenode=root;
        jgo(root->right);
    }

    void recoverTree(TreeNode* root) {
        ferror=lerror=prenode=nullptr;
        jgo(root);
        swap(ferror->val, lerror->val);
    }
};