// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
#include<bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int size=prices.size(),max_k=2,i,k,ans=0;
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(max_k+1, vector<int>(2,0)));
        for(i=0;i<size;++i){
            if(i==0) {
                for(k=0;k<=max_k;++k) dp[i][k][1]=-prices[i];
            }
            else{
                dp[i][0][1]=-prices[i];
                for(k=max_k;k>=1;--k){
                    dp[i][k][0]=max(dp[i-1][k][0], dp[i-1][k][1]+prices[i]); // 保持不持有或者卖出
                    dp[i][k][1]=max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]); // 保持持有或者买入
                }
            }
        }
        return dp[size-1][max_k][0];
    }
};