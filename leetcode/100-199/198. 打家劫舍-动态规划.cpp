// https://leetcode-cn.com/problems/house-robber/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size(), i;
        vector<int>dp(size+2, 0);
        dp[size]=dp[size+1]=0;
        for(i=size-1;i>=0;--i) dp[i]=max(dp[i+2]+nums[i], dp[i+1]);
        return dp[0];
    }
};