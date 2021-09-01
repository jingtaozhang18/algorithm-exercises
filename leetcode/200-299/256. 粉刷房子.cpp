// https://leetcode-cn.com/problems/paint-house/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& costs) {
    int m = costs.size(), i;
    int dp[m + 1][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (i = 0; i < m; ++i) {
      dp[i + 1][0] = min(dp[i][1], dp[i][2]) + costs[i][0];
      dp[i + 1][1] = min(dp[i][0], dp[i][2]) + costs[i][1];
      dp[i + 1][2] = min(dp[i][0], dp[i][1]) + costs[i][2];
    }
    return min({dp[m][0], dp[m][1], dp[m][2]});
  }
};