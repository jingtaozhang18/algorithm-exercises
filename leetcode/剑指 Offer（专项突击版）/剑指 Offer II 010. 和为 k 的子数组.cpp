// https://leetcode-cn.com/problems/QTMn0o/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0]++;
    int acc = 0, ans = 0;
    for (auto& e : nums) {
      acc += e;
      ans += mp[acc - k];  // acc - x = k
      mp[acc]++;
    }
    return ans;
  }
};
