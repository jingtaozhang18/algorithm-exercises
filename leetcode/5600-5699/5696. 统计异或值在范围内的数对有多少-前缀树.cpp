// https://leetcode-cn.com/problems/count-pairs-with-xor-in-a-range/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val, num;
    node *son[2];
    node():val(0){son[0]=son[1]=0;};
};

void build(node *root, int val){
    node *t=root;
    unsigned int f=0x80000000, i, x;
    root->val++;
    for(i=0;i<32;++i){
        x = bool(val&f);
        if(!t->son[x]) t->son[x]=new node();
        t=t->son[x];
        t->val++;
        f=f>>1;
    }
    t->num =val;
}

int find(node *root, int low, int high, int level, int val){
    if(!root) return 0;
    if(level==32) return root->val;
    if(low==0&&high==0xffffffff) return root->val;
    int i, ans=0;
    unsigned int f=0x80000000>>level;
    int fc=bool(val&f);
    // cout<<fc<<" ";
    bool fa=low&f, fb=high&f;
    if(!fa&&!fb){
        ans+=find(root->son[fc], low, high, level+1, val);
    }else if(fa&&!fb){ // 不存在的情况
        cout<<level<<" "<<fa<<" "<<fb<<" "<<low<<" "<<high<<" error!"<<endl;
    }else if(!fa&&fb){ // l==0, high!=0
        ans+=find(root->son[fc], low, 0xffffffff, level+1, val);
        ans+=find(root->son[1-fc], 0, high, level+1, val);
    }else if(fa&&fb){
        ans+=find(root->son[1-fc], low, high, level+1, val);
    }
    return ans;
}

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        node * root=new node();
        int ans=0, i, t;
        for(i=0;i<nums.size();++i){
            t=find(root, low, high, 0, nums[i]);
            build(root, nums[i]);
            // cout<<i<<" "<<t<<endl;
            ans+=t;
        }
        return ans;
    }
};