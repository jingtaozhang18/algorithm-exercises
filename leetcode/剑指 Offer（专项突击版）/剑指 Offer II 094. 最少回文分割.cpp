// https://leetcode-cn.com/problems/omKAoA/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCut(string s) {
    int n = s.size(), i, j, k, a;
    bool isP[n][n];  // 是否是回文
    for (i = 0; i < n; ++i) isP[i][i] = true;
    for (k = 1; k < n; ++k) {
      for (i = 0; i < n - k; ++i) {
        j = i + k;
        isP[i][j] = false;
        if (s[i] == s[j] && (k == 1 || isP[i + 1][j - 1]))
          isP[i][j] = true;  // 整体是
      }
    }
    int dp[n];
    for (i = 0; i < n; ++i) {
      if (isP[0][i])
        dp[i] = 0;
      else {
        dp[i] = INT_MAX;
        for (j = 0; j < i; ++j) {
          if (isP[j + 1][i]) {
            dp[i] = min(dp[i], dp[j] + 1);
          }
        }
      }
    }
    return dp[n - 1];
  }
};