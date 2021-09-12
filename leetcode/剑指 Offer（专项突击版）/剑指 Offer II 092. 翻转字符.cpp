// https://leetcode-cn.com/problems/cyJERH/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    int n = s.size(), i;
    int dp_0[n];  //
    int dp_1[n];  // 1开始出现的位置
    for (i = 0; i < n; ++i) {
      if (i == 0) {
        dp_0[i] = (s[i] != '0') ? 1 : 0;
        dp_1[i] = (s[i] != '1') ? 1 : 0;
      } else {
        if (s[i] == '0') {
          dp_0[i] = dp_0[i - 1];
          dp_1[i] = min(dp_0[i - 1], dp_1[i - 1]) + 1;
        } else {
          dp_1[i] = min(dp_1[i - 1], dp_0[i - 1]);
          dp_0[i] = dp_0[i - 1] + 1;
        }
      }
    }
    return min(dp_0[n - 1], dp_1[n - 1]);
  }
};