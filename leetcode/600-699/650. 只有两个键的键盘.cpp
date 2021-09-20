// https://leetcode-cn.com/problems/2-keys-keyboard/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSteps(int n) {
    int dp[n + 1];
    int x, i, t;
    dp[1] = dp[0] = 0;
    for (i = 2; i <= n; ++i) dp[i] = INT_MAX;
    for (x = 1; x <= n; ++x) {  // 拷贝的数量
      t = 2;
      for (i = x + x; i <= n; i += x) {
        dp[i] = min(dp[i], t + dp[x]);
        ++t;
      }
    }
    return dp[n];
  }
};