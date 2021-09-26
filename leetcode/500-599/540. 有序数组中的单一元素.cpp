// https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, mid;
    while (left < right) {
      mid = left + (right - left) / 2;
      if (mid % 2 == 1) --mid;
      if (nums[mid] == nums[mid + 1])
        left = mid + 2;
      else
        right = mid;
    }
    return nums[left];
  }
};