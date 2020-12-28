// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
      int size=prices.size(), i ,j, p;
      vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(size+1, vector<int>{-10000, 0}));
      for(i=1;i<=k;++i){
        for(j=1;j<=size;++j){
          p=prices[j-1];
          dp[i][j][0]=max(dp[i][j-1][0], dp[i-1][j-1][1]-p); // 持有状态  max({延续本次交易, 从上一次交易中买入})
          dp[i][j][1]=max({dp[i][j-1][0]+p, dp[i-1][j-1][1], dp[i][j-1][1]}); // 未持有状态 max({卖掉此次交易，延续上次未持有，延续本次未持有})
          // 注意由于次数的限制，持有状态不能从当前未持有的状态转移。
          // [i][j][0/1] 至多k次交易时，在第j天持有状态或者未持有状态的最大收益
        }
      }
      return dp[k][size][1];
    }
};