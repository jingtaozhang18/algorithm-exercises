// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<2) return 0;
        int size=prices.size(),max_k=k,i,ans=0;
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(max_k+1, vector<int>(2,0)));
        for(i=0;i<size;++i){
            if(i==0) {
                for(k=0;k<=max_k;++k) dp[i][k][1]=-prices[i];
            }
            else{
                dp[i][0][1]=-prices[i];
                for(k=max_k;k>=1;--k){ // 从后向前遍历，保证不会在次数k时买卖多次
                    dp[i][k][0]=max(dp[i-1][k][0], dp[i-1][k][1]+prices[i]); // 保持不持有或者卖出  未持有状态
                    dp[i][k][1]=max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]); // 保持持有或者买入  持有状态
                }
            }
        }
        return dp[size-1][max_k][0];
    }
};

// 在复习时，对上述算法进行改进。第一次的算法好别扭
// 关键点，要关注的时至多k次交易时的最大收益，而不是第k次交易时的最大收益

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<2) return 0;
        int size=prices.size(),max_k=k,i,ans=0;
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(max_k+1, vector<int>(2,0)));
        for(i=0;i<size;++i){
            if(i==0) {
                for(k=0;k<=max_k;++k) dp[i][k][1]=-prices[i];
            }
            else{
                dp[i][0][1]=-prices[i];
                for(k=1;k<=max_k;++k){ // 从上面的代码中改进，按照在复习时发现的状态转移策略，可以实现正续遍历时也满足条件
                    dp[i][k][0]=max({dp[i-1][k-1][0], dp[i-1][k][0], dp[i-1][k][1]+prices[i]}); // 保持不持有（此次或者上次）或者卖出  得到此刻未持有状态的最大收益
                    dp[i][k][1]=max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]); // 保持持有或者买入（从上次未持有状态）  得到此刻持有状态的最大收益
                }
            }
        }
        return dp[size-1][max_k][0];
    }
};