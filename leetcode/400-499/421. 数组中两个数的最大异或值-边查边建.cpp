// https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
#include<bits/stdc++.h>
using namespace std;

struct node{
    node *left, *right;
    node():left(nullptr),right(nullptr){}
};
class Solution {
public:
    int fn=0x80000000;
    int fl=32;
    node*root;
    void jbuild(int a){
        node*t=root;
        for(int i=0;i<fl;++i,a=(unsigned int)a<<1){
            if(a&fn){
                if(!t->right) t->right=new node();
                t=t->right;
            }else{
                if(!t->left) t->left=new node();
                t=t->left;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        int i, ans=0, t, j, a;
        root=new node();
        node* nd;
        jbuild(nums[0]);
        for(i=1;i<nums.size();++i){
            // 查找nums[i]和之前元素的最优解
            for(a=nums[i],t=0,j=0,nd=root;j<fl;++j,a=(unsigned int)a<<1){
                if(!(a&fn)) {
                    if(nd->right) nd=nd->right, t=(t<<1)+1; else nd=nd->left, t=(t<<1);
                }else {
                    if(nd->left) nd=nd->left, t=(t<<1); else nd=nd->right, t=(t<<1)+1;
                }
            }
            jbuild(nums[i]);
            ans=max(t^nums[i], ans);
        }
        return ans;
    }
};