// https://leetcode-cn.com/problems/gaM7Ch/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int i, x;
    int dp[amount + 1];
    for (i = 0; i <= amount; ++i) dp[i] = 1e4 + 7;
    dp[0] = 0;
    for (auto x : coins) {
      for (i = 0; i + x <= amount; ++i) {
        dp[i + x] = min(dp[i + x], dp[i] + 1);
      }
    }
    return dp[amount] == 1e4 + 7 ? -1 : dp[amount];
  }
};
