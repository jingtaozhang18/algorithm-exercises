// https://leetcode-cn.com/problems/longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),i,j,k,l,r,c,ans=0;
        vector<int> dp(n);
        vector<int> mem(n+1, INT_MAX);
        for(i=0;i<n;++i){
            l=1,r=ans;
            while(l<=r){c=(l+r)>>1; if(mem[c]<nums[i])l=c+1;else r=c-1;}
            k=l, dp[i]=k, ans=max(ans, k), mem[k]=min(mem[k], nums[i]); //记录长度为n的最小值
        }
        return ans;
    }
};
