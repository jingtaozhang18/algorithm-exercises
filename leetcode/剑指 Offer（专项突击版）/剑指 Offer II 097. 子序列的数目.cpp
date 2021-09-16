// https://leetcode-cn.com/problems/21dk04/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numDistinct(string s, string t) {
    int m = s.size(), n = t.size(), i, j;
    unsigned int dp[m + 1][n + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (i = 0; i < m; ++i) {
      dp[i + 1][0] = 1;
      for (j = 0; j < n; ++j) {
        if (s[i] == t[j]) {
          dp[i + 1][j + 1] = dp[i][j + 1] + dp[i][j];
        } else {
          dp[i + 1][j + 1] = dp[i][j + 1];
        }
      }
    }
    return dp[m][n];
  }
};
