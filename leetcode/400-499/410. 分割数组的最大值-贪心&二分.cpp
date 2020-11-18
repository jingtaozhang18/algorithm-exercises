// https://leetcode-cn.com/problems/split-array-largest-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jgo(vector<int>& nums, long long t, int m){ // 累加和小于等于t的情况下能否满足情况
        long long x;
        int i, seg=0;
        for(i=0,x=0,seg=0;i<nums.size();++i){
            if(nums[i]>t) return false;
            if(x+nums[i]>t){
                seg++, x=0;
                if(seg>m) return false;
            }
            x+=nums[i];
        }
        seg++;
        return seg<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        long long l,c,r;
        int i;
        l=0,r=0;
        for(i=0;i<nums.size();++i) r+=nums[i];
        while(l<=r){
            c=(l+r)>>1;
            if(jgo(nums, c, m)) r=c-1;
            else l=c+1;
        }
        return l;
    }
};