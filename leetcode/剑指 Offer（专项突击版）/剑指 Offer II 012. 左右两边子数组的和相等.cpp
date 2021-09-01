// https://leetcode-cn.com/problems/tvdfij/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int i, m = nums.size(), x, y;
    int acc[m + 1];
    acc[0] = 0;
    for (i = 0; i < m; ++i) acc[i + 1] = acc[i] + nums[i];
    for (i = 0; i < m; ++i) {
      x = i ? acc[i] : 0;
      y = acc[m] - acc[i + 1];
      if (x == y) return i;
    }
    return -1;
  }
};