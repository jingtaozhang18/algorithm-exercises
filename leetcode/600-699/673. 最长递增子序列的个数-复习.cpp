// https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size(), i, j, x, y, t, ansT = 0, ansK = 0;
    int dp[n];  // 最长的长度
    int kind[n];
    for (i = 0; i < n; ++i) {
      x = -1, y = 0, t = 1;
      for (j = i - 1; j >= 0; --j) {
        if (nums[j] < nums[i]) {
          if (dp[j] > y) {  //
            x = i, y = dp[j], t = kind[j];
          } else if (dp[j] == y)
            t += kind[j];
        }
      }
      dp[i] = y + 1;
      kind[i] = t;
      if (dp[i] > ansT)
        ansT = dp[i], ansK = kind[i];
      else if (dp[i] == ansT)
        ansK += kind[i];
    }
    return ansK;
  }
};