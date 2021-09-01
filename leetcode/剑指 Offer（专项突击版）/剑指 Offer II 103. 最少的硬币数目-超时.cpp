// https://leetcode-cn.com/problems/gaM7Ch/
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int m = coins.size(), i, j, k, x;
    int dp[m + 1][amount + 1];
    for (i = 0; i < m + 1; ++i)
      for (j = 0; j <= amount; ++j) dp[i][j] = 1e4 + 7;
    dp[0][0] = 0;
    for (i = 1; i <= m; ++i) {
      for (j = 0; j <= amount; ++j) {  // 用前i个拼凑j元
        if (j == 0)
          dp[i][j] = 0;
        else {
          for (k = 0; (x = j - coins[i - 1] * k) >= 0; ++k) {
            dp[i][j] = min(dp[i][j], dp[i - 1][x] + k);
          }
        }
      }
    }
    return dp[m][amount] == 1e4 + 7 ? -1 : dp[m][amount];
  }
};