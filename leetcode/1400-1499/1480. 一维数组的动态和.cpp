// https://leetcode-cn.com/problems/running-sum-of-1d-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    int i, n = nums.size();
    for (i = 1; i < n; ++i) nums[i] += nums[i - 1];
    return nums;
  }
};