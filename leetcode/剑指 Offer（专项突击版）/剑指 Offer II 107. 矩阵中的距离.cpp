// https://leetcode-cn.com/problems/2bCMpM/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size(), i, j, k, x, y;
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    queue<pair<int, int>> que;
    vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          que.emplace(i, j);
          distance[i][j] = 0;
        }
      }
    }
    while (que.size()) {
      auto [i, j] = que.front();
      que.pop();
      for (k = 0; k < 4; ++k) {
        x = i + dir[k][0];
        y = j + dir[k][1];
        if (x >= 0 && x < m && y >= 0 && y < n) {
          if (distance[x][y] > distance[i][j] + 1) {
            que.emplace(x, y);
            distance[x][y] = distance[i][j] + 1;
          }
        }
      }
    }
    return distance;
  }
};