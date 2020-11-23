// https://leetcode-cn.com/problems/longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),i,j,k,ans=0;
        vector<int> dp(n);
        for(i=0;i<n;++i){
            for(j=0,k=0;j<i;++j) if(nums[j]<nums[i]) k=max(k, dp[j]);
            dp[i]=k+1, ans=max(ans, dp[i]);
        }
        return ans;
    }
};