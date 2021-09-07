// https://leetcode-cn.com/problems/A1NYOS/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int balance = 0, n = nums.size(), i, ans = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (i = 0; i < n; ++i) {
      if (nums[i] == 0)
        ++balance;
      else
        --balance;
      if (mp.find(balance) == mp.end()) {
        mp[balance] = i;
      } else {
        ans = max(ans, i - mp[balance]);
      }
    }
    return ans;
  }
};
