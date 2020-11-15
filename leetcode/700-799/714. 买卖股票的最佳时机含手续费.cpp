// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // [i][1] 第i天手里有股票， [i][0]第i天手里没有股票
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        int i;
        dp[0][0]=0, dp[0][1]=-prices[0];
        for(i=1;i<prices.size();++i){
            dp[i][1]=max(dp[i-1][1], dp[i-1][0]-prices[i]); // 维持现状或者买入股票
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i]-fee); // 维持现状或者卖掉股票
        }
        return dp[prices.size()-1][0];
    }
};