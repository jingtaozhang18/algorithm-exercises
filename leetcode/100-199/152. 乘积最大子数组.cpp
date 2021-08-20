// https://leetcode-cn.com/problems/maximum-product-subarray/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int m = nums.size(), i;
    if (m == 0) return 0;
    long long pos = INT_MIN, neg = INT_MAX, op, on, ans = INT_MIN;
    for (auto& x : nums) {
      if (x >= 0) {
        op = pos, on = neg;
        if (op > 0)
          pos = x * op;
        else
          pos = x;
        if (on < 0)
          neg = on * x;
        else
          neg = INT_MAX;
      } else {  // 负数
        op = pos, on = neg;
        if (on < 0)
          pos = on * x;
        else
          pos = INT_MIN;
        if (op > 0)
          neg = x * op;
        else
          neg = x;
      }
      if (pos >= 0) ans = max(ans, pos);
      if (neg < 0) ans = max(ans, neg);
    }
    return ans;
  }
};