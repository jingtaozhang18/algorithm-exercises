// https://leetcode-cn.com/problems/house-robber-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size(), i, ans=0;
        if(size==0) return 0;
        if(size==1) return nums[0];
        vector<int>dp(size, 0);
        // 偷最后一家
        dp[size-1]=nums[size-1];
        for(i=size-2;i>0;--i) if(i+2<size) dp[i]=max(dp[i+2]+nums[i], dp[i+1]); else dp[i]=max(nums[i], dp[i+1]);
        ans=dp[1]; // 错误点，不能判断下标1一定存在
        // 不偷最后一家
        dp[size-1]=0;
        for(i=size-2;i>=0;--i) if(i+2<size) dp[i]=max(dp[i+2]+nums[i], dp[i+1]); else dp[i]=max(nums[i], dp[i+1]);
        ans=max(ans,dp[0]);
        return ans;
    }
};