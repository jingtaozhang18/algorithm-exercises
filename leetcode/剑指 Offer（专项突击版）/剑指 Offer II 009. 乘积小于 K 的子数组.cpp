// https://leetcode-cn.com/problems/ZVAVXX/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int left = 0, right = 0, ans = 0;
    long long acc = 1;
    while (right < nums.size()) {
      acc *= nums[right++];
      while (left < right && acc >= k) acc /= nums[left++];
      if (acc < k) ans += (right - left);  // right 已经加过1了
    }
    return ans;
  }
};
