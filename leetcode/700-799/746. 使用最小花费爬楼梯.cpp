// https://leetcode-cn.com/problems/min-cost-climbing-stairs/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i,j,size=cost.size();
        vector<int> dp(size+1, INT_MAX);
        dp[0]=dp[1]=0;
        for(i=0;i<size;++i){
            dp[i+1]=min(dp[i+1], dp[i]+cost[i]);
            if(i!=size-1) dp[i+2]=min(dp[i+2], dp[i]+cost[i]);
        }
        return dp[size];
    }
};