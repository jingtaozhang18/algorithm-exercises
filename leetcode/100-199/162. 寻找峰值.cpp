// https://leetcode-cn.com/problems/find-peak-element/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, mid, x, y;
    while (left <= right) {
      mid = left + (right - left) / 2;
      x = nums[mid];
      y = (mid < nums.size() - 1) ? nums[mid + 1] : INT_MIN;
      if (x < y)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return left;
  }
};