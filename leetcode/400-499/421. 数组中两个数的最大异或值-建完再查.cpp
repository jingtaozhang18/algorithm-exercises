// https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
#include<bits/stdc++.h>
using namespace std;


struct node{
    node *left, *right;
    node():left(nullptr),right(nullptr){}
};
class Solution {
public:
    node*root;
    int fn=0x80000000; // 32位，第一位为1,其余位为0
    int fl=32; // 32位整数
    void jbuild(vector<int>& nums){
        root=new node();
        node* t;
        int i, j, a;
        for(i=0;i<nums.size();++i){
            a=nums[i], t=root;
            // cout<<a<<" "<<bitset<32>(a)<<endl;
            for(j=0;j<fl;++j,a=(unsigned int)a<<1){
                if(a&fn) {if(!t->right) t->right=new node(); t=t->right;}
                else {if(!t->left) t->left=new node(); t=t->left;}
            }
        }
    }
    // 需要递归的原因是 当两个节点的左右孩子都存在的时候，是存在不知道哪条路更好的情况
    int jgo(node* ta, node* tb, int a, int b, int level){
        if(level==fl) return a^b;
        int ans=0;
        if(ta->left&&tb->right) ans=max(ans, jgo(ta->left, tb->right, (a<<1), (b<<1)+1, level+1));
        if(ta->right&&tb->left) ans=max(ans, jgo(ta->right, tb->left, (a<<1)+1, (b<<1), level+1));
        if(ta->left&&tb->left&&!ta->right&&!tb->right) ans=max(ans, jgo(ta->left, tb->left, (a<<1), (b<<1), level+1));
        if(ta->right&&tb->right&&!ta->left&&!tb->left) ans=max(ans, jgo(ta->right, tb->right, (a<<1)+1, (b<<1)+1, level+1));
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        jbuild(nums);
        return jgo(root,root,0,0,0);
    }
};