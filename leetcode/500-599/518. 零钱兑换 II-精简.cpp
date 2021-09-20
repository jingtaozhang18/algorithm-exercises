// https://leetcode-cn.com/problems/coin-change-2/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (auto& p : coins) {
      for (int i = p; i <= amount; i++) {
        dp[i] += dp[i - p];
      }
    }
    return dp[amount];
  }
};

// ys 理解, 如果写成下面的方式，就是排列的数量
class Solution_pailie {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int i = 0; i <= amount; i++) {
      for (auto& p : coins) {
        if (i - p >= 0) dp[i] += dp[i - p];
      }
    }
    return dp[amount];
  }
};
