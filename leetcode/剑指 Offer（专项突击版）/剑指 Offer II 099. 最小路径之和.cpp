// https://leetcode-cn.com/problems/0i0mDW/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), i, j, x;
    int dp[m][n];
    for (i = 0; i < m; ++i)
      for (j = 0; j < n; ++j) dp[i][j] = INT_MAX;
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
        if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
        if (!i && !j) dp[i][j] = grid[i][j];
      }
    }
    return dp[m - 1][n - 1];
  }
};
