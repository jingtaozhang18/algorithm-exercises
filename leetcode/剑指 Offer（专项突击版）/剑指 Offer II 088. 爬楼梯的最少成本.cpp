// https://leetcode-cn.com/problems/GzCJIP/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int i, j, n = cost.size();
    int dp[n + 1];
    for (i = 0; i <= n; ++i) dp[i] = INT_MAX;
    dp[0] = dp[1] = 0;
    for (i = 0; i < n; ++i) {
      for (j = 1; i + j <= n && j <= 2; ++j) {
        dp[i + j] = min(dp[i] + cost[i], dp[i + j]);
      }
    }
    return dp[n];
  }
};