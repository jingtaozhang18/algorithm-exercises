// https://leetcode-cn.com/problems/decode-ways-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int judge(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return -1;
  }
  int numDecodings(string s) {
    int m = s.size(), i, x, pre, mod = 1e9 + 7;
    unsigned long long dp[m + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (i = 1; i <= m; ++i) {
      x = judge(s[i - 1]);
      if (x == -1) {
        dp[i] += dp[i - 1] * 9;
      } else if (x == 0) {
        ;
      } else {
        dp[i] = dp[i - 1];
      }
      dp[i] %= mod;
      if (i > 1) {
        pre = judge(s[i - 2]);
        if (pre == -1) {
          if (x == -1) {
            dp[i] += dp[i - 2] * 15;
          } else if (x <= 6) {
            dp[i] += dp[i - 2] * 2;
          } else {
            dp[i] += dp[i - 2];
          }
        } else if (pre == 0) {
          ;
        } else if (pre == 1) {
          if (x == -1) {
            dp[i] += dp[i - 2] * 9;
          } else {
            dp[i] += dp[i - 2];
          }
        } else if (pre == 2) {
          if (x == -1) {
            dp[i] += dp[i - 2] * 6;
          } else if (x <= 6) {
            dp[i] += dp[i - 2];
          } else {
            ;
          }
        }
        dp[i] %= mod;
      }
    }
    return dp[m];
  }
};
