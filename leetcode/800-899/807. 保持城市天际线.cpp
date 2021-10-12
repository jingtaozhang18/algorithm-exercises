// https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), i, j, x;
    vector<int> row(m);
    vector<int> col(n);
    for (i = 0;i < m;++i) {
      for (j = x = 0;j < n;++j) {
        x = max(x, grid[i][j]);
      }
      row[i] = x;
    }
    for (j = 0;j < n;++j) {
      for (i = x = 0;i < m;++i) {
        x = max(x, grid[i][j]);
      }
      col[j] = x;
    }
    int ans = 0;
    for (i = 0;i < m;++i) {
      for (j = 0;j < n;++j) {
        ans += min(row[i], col[j]) - grid[i][j];
      }
    }
    return ans;
  }
};