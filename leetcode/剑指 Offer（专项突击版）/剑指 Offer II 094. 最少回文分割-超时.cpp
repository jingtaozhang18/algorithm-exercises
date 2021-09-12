// https://leetcode-cn.com/problems/omKAoA/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCut(string s) {
    int n = s.size(), i, j, k, a;
    int dp[n][n];
    for (i = 0; i < n; ++i) dp[i][i] = 0;
    for (k = 1; k < n; ++k) {
      for (i = 0; i < n - k; ++i) {
        j = i + k;
        dp[i][j] = 20000;
        if (s[i] == s[j] && (k == 1 || dp[i + 1][j - 1] == 0))
          dp[i][j] = 0;  // 整体是
        else {
          for (a = i; a < j; ++a) {  // [i, a]+[a+1, j];  枚举切一刀的位置
            dp[i][j] = min(dp[i][j], dp[i][a] + dp[a + 1][j] + 1);
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};