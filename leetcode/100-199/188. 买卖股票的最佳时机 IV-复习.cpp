// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(int k, vector<int> &prices)
  {
    int size = prices.size(), i, j, p;
    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(size + 1, vector<int>{-10000, 0}));
    for (i = 1; i <= k; ++i)
    {
      for (j = 1; j <= size; ++j)
      {
        p = prices[j - 1];
        dp[i][j][0] = max(dp[i][j - 1][0], dp[i - 1][j - 1][1] - p);                    // 持有状态  max({延续本次交易, 从上一次交易中买入})
        dp[i][j][1] = max({dp[i][j - 1][0] + p, dp[i - 1][j - 1][1], dp[i][j - 1][1]}); // 未持有状态 max({卖掉此次交易，延续上次未持有，延续本次未持有})
        // 注意由于次数的限制，持有状态不能从当前未持有的状态转移。
        // [i][j][0/1] 至多k次交易时，在第j天持有状态或者未持有状态的最大收益
      }
    }
    return dp[k][size][1];
  }
};

class Solution_fx
{
public:
  int maxProfit(int k, vector<int> &prices)
  {
    int m = prices.size(), i, j, ans = 0;
    // first 不持有
    // second 持有
    vector<vector<pair<int, int>>> dp(m + 1, vector<pair<int, int>>(k + 1, make_pair(0, INT_MIN)));
    for (i = 1; i <= m; ++i)
    {
      for (j = 1; j <= k; ++j)
      {
        dp[i][j].first = max(dp[i - 1][j].first, dp[i - 1][j].second + prices[i - 1]);      // 不持有, from {本次未持有， 本次卖出}
        dp[i][j].second = max(dp[i - 1][j].second, dp[i - 1][j - 1].first - prices[i - 1]); // 持有, from {本次持有， 从上次买入}
        ans = max(ans, dp[i][j].first);
      }
    }
    return ans;
  }
};
