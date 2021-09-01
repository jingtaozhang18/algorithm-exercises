// https://leetcode-cn.com/problems/qJnOS7/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size(), i, j;
    // vector<vector<int>> dp(m, vector<int>(n, 0));
    // 使用栈空间速度会更快
    int dp[m][n];
    for(i=0;i<m;++i) for(j=0;j<n;++j) dp[i][j]=0;
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        if (text1[i] != text2[j]) {
          if (i) dp[i][j] = max(dp[i - 1][j], dp[i][j]);
          if (j) dp[i][j] = max(dp[i][j - 1], dp[i][j]);
          if (i && j) dp[i][j] = max(dp[i - 1][j - 1], dp[i][j]);
        } else {
          if (i && j)
            dp[i][j] = dp[i - 1][j - 1] + 1;
          else
            dp[i][j] = 1;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};