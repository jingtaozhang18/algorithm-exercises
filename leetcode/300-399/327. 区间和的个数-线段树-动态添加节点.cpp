// https://leetcode-cn.com/problems/count-of-range-sum/
#include<bits/stdc++.h>
using namespace std;

struct node{
    long long low, high; // 闭区间
    int add;
    node*left,*right;
    node(long long  low, long long high):low(low),high(high),add(0),left(nullptr),right(nullptr){}
};
class Solution {
public:
    void jinsert(node*root, long long val){
        root->add++; // 整个段增加
        if(root->low==root->high) return;
        long long mid=(root->low+root->high)>>1;
        if(val<=mid){ // 向左边添加
            if(!root->left) root->left=new node(root->low, mid);
            jinsert(root->left, val);
        }else{
            if(!root->right) root->right=new node(mid+1, root->high);
            jinsert(root->right, val);
        }
    }
    int jcount(node*root, long long  low, long long high){
        if(!root||root->high<low||root->low>high) return 0;
        if(root->low>=low&&root->high<=high) return root->add;
        return jcount(root->left, low, high)+jcount(root->right, low, high);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size()==0) return false;
        int i,ans=0,k; long long mav=0,miv=0,t;
        for(i=0,t=0;i<nums.size();++i) t+=nums[i], mav=max({mav,t,t-lower,t-upper}), miv=min({miv,t,t-lower,t-upper}); // 找出线段树的边界
        node* root=new node(miv, mav);
        jinsert(root, 0); // 初始化
        for(i=0,t=0;i<nums.size();++i){
            t+=nums[i];
            k=jcount(root, t-upper, t-lower);
            ans+=k;
            jinsert(root, t);
        }
        return ans;
    }
};