// https://leetcode-cn.com/problems/binary-search/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size(), mid;
    while (left <= right) {
      mid = (left + right) >> 1;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return -1;
  }
};