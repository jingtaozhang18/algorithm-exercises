// https://leetcode-cn.com/problems/maximum-score-from-performing-multiplication-operations/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  unordered_map<long long, int> mem;
  int calc(vector<int>& nums, vector<int>& multipliers, int left, int right) {
    int m = nums.size(), n = multipliers.size();
    int index = left + m - 1 - right;
    long long key = left * m + right;
    auto p = mem.find(key);
    if (p != mem.end()) return p->second;
    if (index == n - 1) {
      return mem[key] = max(nums[left] * multipliers[index],
                            nums[right] * multipliers[index]);
    } else {
      return mem[key] = max(calc(nums, multipliers, left + 1, right) +
                                nums[left] * multipliers[index],
                            calc(nums, multipliers, left, right - 1) +
                                nums[right] * multipliers[index]);
    }
  }
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int m = nums.size(), n = multipliers.size();
    return calc(nums, multipliers, 0, m - 1);
  }
};
