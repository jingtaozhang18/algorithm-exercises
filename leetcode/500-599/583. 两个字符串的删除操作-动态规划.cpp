// https://leetcode-cn.com/problems/delete-operation-for-two-strings/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size(), i, j;
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for (i = 1; i <= m; ++i) dp[i][0] = i;
    for (j = 1; j <= n; ++j) dp[0][j] = j;
    for (i = 1; i <= m; ++i) {
      for (j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = INT_MAX;
        }
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 2);
      }
    }
    return dp[m][n];
  }
};