// https://leetcode-cn.com/problems/PLYXKQ/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<string>& matrix) {
    int i, j, m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    if (n == 0) return 0;
    stack<int> sta;
    int left[n], right[n], ans = 0, row[n];
    for (j = 0; j < n; ++j) row[j] = 0;
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        if (matrix[i][j] == '1')
          row[j]++;
        else
          row[j] = 0;
      }
      // 对matrix[i]行使用单调栈进行计算
      while (sta.size()) sta.pop();
      for (j = 0; j < n; ++j) {
        while (sta.size() && row[sta.top()] > row[j]) {
          right[sta.top()] = j;
          sta.pop();
        }
        left[j] = sta.size() ? sta.top() : -1;
        sta.push(j);
      }
      while (sta.size()) {
        right[sta.top()] = j;
        sta.pop();
      }
      for (j = 0; j < n; ++j) {
        ans = max(ans, row[j] * (right[j] - left[j] - 1));
      }
    }
    return ans;
  }
};
