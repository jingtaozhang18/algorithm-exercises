// https://leetcode-cn.com/problems/Gu0c2T/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size(), i, j, dp[n];
    for (i = 0; i < n; ++i) dp[i] = 0;
    for (i = 0; i < n; ++i) {
      if (i - 1 >= 0) dp[i] = dp[i - 1];  // 不偷
      dp[i] = max(dp[i], (i - 2 >= 0 ? dp[i - 2] : 0) + nums[i]);
    }
    return dp[n - 1];
  }
};