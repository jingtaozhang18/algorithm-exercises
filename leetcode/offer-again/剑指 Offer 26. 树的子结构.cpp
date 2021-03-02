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
    bool judge(TreeNode *root, TreeNode * child){
      if(!child) return true;
      return root && root->val==child->val && judge(root->left, child->left) && judge(root->right, child->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) { // 自身在进行遍历尝试
      if(!A||!B) return false; // 防御性编程
      return judge(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};