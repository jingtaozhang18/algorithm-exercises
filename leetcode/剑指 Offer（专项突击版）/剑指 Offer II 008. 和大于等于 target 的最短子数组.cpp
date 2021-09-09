// https://leetcode-cn.com/problems/2VG8Kg/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0, ans = INT_MAX;
    long long acc = 0;
    while (right < nums.size()) {
      acc += nums[right++];
      while (left < right && acc >= target) acc -= nums[left++];
      if (left && acc + nums[left - 1] >= target)
        ans = min(ans, right - left + 1);
    }
    return ans == INT_MAX ? 0 : ans;
  }
};