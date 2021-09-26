// https://leetcode-cn.com/problems/2AoeFn/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int dp[m][n], i, j;
    memset(dp, 0, sizeof dp);
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        if (i == 0 && j == 0)
          dp[i][j] = 1;
        else {
          if (i) dp[i][j] += dp[i - 1][j];
          if (j) dp[i][j] += dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};