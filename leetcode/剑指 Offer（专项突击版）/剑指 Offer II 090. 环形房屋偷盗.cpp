// https://leetcode-cn.com/problems/PzWKhm/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int m = nums.size(), i, ans;
    if (m == 0) return 0;
    if (m == 1) return nums[0];
    int acc[m][2];  // 0是不偷， 1是偷
    memset(acc, 0, sizeof(acc));
    acc[0][1] = nums[0];
    for (i = 1; i < m - 1; ++i) {
      acc[i][1] = acc[i - 1][0] + nums[i];
      acc[i][0] = max(acc[i - 1][0], acc[i - 1][1]);
    }
    ans = max(acc[m - 2][0], acc[m - 2][1]);
    acc[0][1] = 0;
    for (i = 1; i < m; ++i) {
      acc[i][1] = acc[i - 1][0] + nums[i];
      acc[i][0] = max(acc[i - 1][0], acc[i - 1][1]);
    }
    ans = max(max(acc[m - 1][0], acc[m - 1][1]), ans);
    return ans;
  }
};