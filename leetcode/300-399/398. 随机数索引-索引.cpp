// https://leetcode-cn.com/problems/random-pick-index/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  unordered_map<int, vector<int>> mp;
  Solution(vector<int>& nums) {
    int i = 0, n = nums.size();
    for (i = 0; i < n; ++i) {
      mp[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    auto p = mp.find(target);
    int i = rand() % p->second.size();
    return *(p->second.begin() + i);
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */