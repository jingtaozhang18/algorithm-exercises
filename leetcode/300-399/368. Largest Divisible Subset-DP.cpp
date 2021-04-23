// https://leetcode-cn.com/problems/largest-divisible-subset/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, j, n=nums.size(), maxv, ans=0;
        int dp[n];
        int pre[n];
        for(i=0;i<n;++i){
            dp[i]=1, pre[i]=i;
            for(maxv=0,j=i-1;j>=0;--j) if(nums[i]%nums[j]==0&&dp[j]+1>dp[i]) {dp[i]=dp[j]+1; pre[i]=j;}
            if(dp[i]>dp[ans]) ans=i;
        }
        vector<int> res;
        while(ans!=pre[ans]){
            res.push_back(nums[ans]);
            ans=pre[ans];
        };
        res.push_back(nums[ans]);
        return res;
    }
};