// https://leetcode-cn.com/problems/the-masseuse-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        int m=nums.size(), i, j;
        int dp[m+1][2]; // dp[i][0] 第i个预约不约
        dp[0][0]=dp[0][1]=0;
        for(i=0;i<m;++i){
            dp[i+1][1]=dp[i][0]+nums[i];
            dp[i+1][0]=max(dp[i][1], dp[i][0]); // 必须有max判断
        }
        return max(dp[m][0], dp[m][1]);
    }
};