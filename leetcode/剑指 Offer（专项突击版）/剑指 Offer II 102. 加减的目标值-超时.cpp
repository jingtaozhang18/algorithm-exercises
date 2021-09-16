// https://leetcode-cn.com/problems/YaVDxD/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size(), status = 0, i, x, ans = 0;
    for (status = 0; status < (1 << n); ++status) {
      x = 0;
      for (i = 0; i < n; ++i) {
        if (status & (1 << i))
          x += nums[i];
        else
          x -= nums[i];
      }
      if (x == target) ++ans;
    }
    return ans;
  }
};