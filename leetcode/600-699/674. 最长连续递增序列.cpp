// https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i,j,size=nums.size(),ans=1;
        if(!size) return 0;
        vector<int> dp(size);
        dp[0]=1;
        for(i=1;i<size;++i){
            dp[i]=nums[i]>nums[i-1]?dp[i-1]+1:1;
            ans=max(dp[i], ans);
        }
        return ans;
    }
};