// https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/
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
    vector<int> ans;
    void visit(TreeNode* root, int level, int target){
        if(!root) return;
        if(level==target){
            ans.push_back(root->val);
            return;
        }
        visit(root->left, level+1, target);
        visit(root->right, level+1, target);
    }
    int jgo(TreeNode* root, TreeNode* target, int k){
        if(!root) return 0;
        if(root==target) { // 找到了目标节点，向下找完之后，开始回溯
            visit(root, 0, k);
            return 1;
        }
        int left=jgo(root->left, target, k);
        if(left>0){ // 左侧发现了targe节点
            if(left==k) ans.push_back(root->val);
            if(left<k){
                visit(root->right, left+1, k);
            }
        }
        int right=jgo(root->right, target, k);
        if(right>0){ // 右侧发现了target节点
            if(right==k) ans.push_back(root->val);
            if(right<k){
                visit(root->left, right+1, k);
            }
        }
        if(left>0) return left+1;
        if(right>0) return right+1;
        return 0;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        jgo(root, target, k);
        return ans;
    }
};