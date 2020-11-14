// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int size=prices.size(),i,j,k;
        vector<vector<int>> dp(size, vector<int>(2,0));
        for(i=0;i<size;++i){
            if(i==0){
                dp[i][1]=-prices[i];
            }else{
                if(i>1) dp[i][1]=max(dp[i-1][1], dp[i-2][0]-prices[i]); // 持有或买入
                else dp[i][1]=max(dp[i-1][1], dp[i-1][0]-prices[i]); // 第2天的时候没有等待限制
                dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i]); // 不持有，卖出没有限制
            }
        }
        return dp[size-1][0];
    }
};