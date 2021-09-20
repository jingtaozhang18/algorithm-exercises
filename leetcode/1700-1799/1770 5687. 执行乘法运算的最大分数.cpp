// https://leetcode-cn.com/problems/maximum-score-from-performing-multiplication-operations/
#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int i, j, k, m=nums.size(), n=multipliers.size(), ans=INT_MIN; // 开头取i个， 末尾取j个, 一共取k=i+j个
        for(k=1;k<=n;++k){
            for(i=0;i<=k;++i){
                j=k-i;
                if(i==0) dp[i][j]=dp[i][j-1]+nums[m-j]*multipliers[k-1]; // n-k+i 最后一个元素的位置, 从后面取
                else if(j==0) dp[i][j]=dp[i-1][j]+nums[i-1]*multipliers[k-1]; // 从前面取
                else dp[i][j] = max(dp[i][j-1]+nums[m-j]*multipliers[k-1],
                                    dp[i-1][j]+nums[i-1]*multipliers[k-1]);
                if(k==n) ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};