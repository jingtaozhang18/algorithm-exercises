// https://leetcode-cn.com/problems/fpTFWP/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int ans = 0, m, n;
  int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
  int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dis) {
    int x, y, k;
    if (dis[i][j]) return dis[i][j];
    dis[i][j] = 1;
    for (k = 0; k < 4; ++k) {
      x = i + dir[k][0];
      y = j + dir[k][1];
      if (x >= 0 && x < m && y >= 0 && y < n) {
        if (matrix[x][y] < matrix[i][j]) {
          dis[i][j] = max(dis[i][j], dfs(x, y, matrix, dis) + 1);
        }
      }
    }
    return dis[i][j];
  };
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();
    vector<vector<int>> dis(m, vector<int>(n, 0));
    int i, j;
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        ans = max(ans, dfs(i, j, matrix, dis));
      }
    }
    return ans;
  }
};