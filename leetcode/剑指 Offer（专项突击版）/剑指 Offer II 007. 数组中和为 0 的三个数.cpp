// https://leetcode-cn.com/problems/1fGaJU/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i, j, k, x, n = nums.size();
    vector<vector<int>> ans;
    k = n - 1;
    for (i = 0; i < n;) {
      j = i + 1, k = n - 1;
      while (j < k) {
        x = nums[i] + nums[j] + nums[k];
        if (x == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});
          do {
            ++j;
          } while (j < k && nums[j] == nums[j - 1]);
          do {
            --k;
          } while (j < k && nums[k] == nums[k + 1]);
        } else if (x < 0)
          do {
            ++j;
          } while (j < k && nums[j] == nums[j - 1]);
        else
          do {
            --k;
          } while (j < k && nums[k] == nums[k + 1]);
      }
      do {
        ++i;
      } while (i < n && nums[i] == nums[i - 1]);
    }
    return ans;
  }
};
