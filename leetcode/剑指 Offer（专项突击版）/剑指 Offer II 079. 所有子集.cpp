// https://leetcode-cn.com/problems/TVdhkn/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int i, j;
    vector<vector<int>> ans;
    for (i = 0; i < 1 << n; ++i) {
      vector<int> t;
      for (j = 0; j < n; ++j) {
        if ((1 << j) & i) t.push_back(nums[j]);
      }
      ans.push_back(t);
    }
    return ans;
  }
};