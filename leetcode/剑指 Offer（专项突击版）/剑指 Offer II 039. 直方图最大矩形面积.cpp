// https://leetcode-cn.com/problems/0ynMMM/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int ans = 0, i, n = heights.size();
    stack<int> sta;
    vector<int> left(n);
    vector<int> right(n);
    for (i = 0; i < n; ++i) {
      while (sta.size() && heights[sta.top()] > heights[i]) {
        right[sta.top()] = i;
        sta.pop();
      }
      left[i] = sta.size() ? sta.top() : -1;
      sta.push(i);
    }
    while (sta.size()) {
      right[sta.top()] = n;
      sta.pop();
    }
    for (i = 0; i < n; ++i) {
      ans = max(heights[i] * (right[i] - left[i] - 1), ans);
    }
    return ans;
  }
};