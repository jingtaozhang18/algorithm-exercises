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

class Solution {
public:
    int rob(vector<int>& nums) {
        int i, j, n=nums.size(), ans=0;
        if(n==0) return 0;
        if(n==1) return nums[0];
        // 可能会偷第一家
        int dp[n][2]; // 0是不偷，1是偷
        for(i=0;i<n;++i) dp[i][0]=0, dp[i][1]=0;
        dp[0][1]=nums[0];
        for(i=1;i<n-1;++i){
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        ans=max(dp[n-2][0], dp[n-2][1]);
        
        // 不偷第一家
        for(i=0;i<n;++i) dp[i][0]=0, dp[i][1]=0;
        for(i=1;i<n;++i){
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        ans=max(max(ans, dp[n-1][0]), dp[n-1][1]);
        return ans;
    }
};