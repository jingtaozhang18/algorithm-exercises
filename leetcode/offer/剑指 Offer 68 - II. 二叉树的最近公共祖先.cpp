// https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
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
    TreeNode* jgo(TreeNode* root, TreeNode *p, TreeNode *q, bool& h){
        TreeNode* ans=nullptr;
        if(!root) return ans;
        int hit=0;
        if(root->val==p->val||root->val==q->val) hit++, h=true;
        bool hl=false, hr=false;
        if((ans=jgo(root->left, p, q, hl))) return ans;
        if((ans=jgo(root->right, p, q, hr))) return ans;
        if(hl) hit++,h=true; if(hr) hit++,h=true;
        if(hit==2) return root;
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool f;
        return jgo(root, p, q, f);
    }
};