// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
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
    TreeNode* copy(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* ans = new TreeNode(root->val);
        ans->left = copy(root->left);
        ans->right = copy(root->right);
        return ans;
    }
    vector<TreeNode*> jgo(int left, int right){
        int i;
        if(left>right) {
            return { nullptr };
        }
        vector<TreeNode*> ans;
        for(i=left;i<=right;++i){
            vector<TreeNode*> lchild = jgo(left, i-1);
            vector<TreeNode*> rchild = jgo(i+1, right);
            for(auto& l:lchild){
                for(auto& r:rchild){
                    auto root=new TreeNode(i);
                    root->left = l;//copy(l);
                    root->right = r;//copy(r);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return jgo(1, n);
    }
};