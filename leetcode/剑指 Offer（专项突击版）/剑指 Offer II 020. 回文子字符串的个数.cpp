// https://leetcode-cn.com/problems/a7VOhD/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countSubstrings(string s) {
    int m = s.size(), i, j, d, ans = 0;
    bool dp[m][m];
    memset(dp, 0, sizeof dp);
    for (d = 0; d < m; ++d) {
      for (i = 0; i < m - d; ++i) {
        j = i + d;
        if (s[i] == s[j] && (d <= 1 || dp[i + 1][j - 1]))
          dp[i][j] = true, ++ans;
        else
          dp[i][j] = false;
      }
    }
    return ans;
  }
};
