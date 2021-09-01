// https://leetcode-cn.com/problems/SsGoHC/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    int i, j, m = intervals.size();
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);
    for (i = 1; i < m; ++i) {
      if (intervals[i][0] <= ans.back()[1]) {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      } else {
        ans.push_back(intervals[i]);
      }
    }
    return ans;
  }
};