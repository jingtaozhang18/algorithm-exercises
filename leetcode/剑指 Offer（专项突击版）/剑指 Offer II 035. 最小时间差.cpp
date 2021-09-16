// https://leetcode-cn.com/problems/569nqc/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    int i = 0, n = timePoints.size(), x;
    vector<int> t(n);
    for (auto& timePoint : timePoints) {
      x = ((timePoint[0] - '0') * 10 + (timePoint[1] - '0')) * 60 +
          ((timePoint[3] - '0') * 10 + (timePoint[4] - '0'));
      t[i++] = x;
    }
    sort(t.begin(), t.end());
    int ans = 24 * 60 + t[0] - t[n - 1];
    for (i = 1; i < n; ++i) {
      ans = min(ans, t[i] - t[i - 1]);
    }
    return ans;
  }
};