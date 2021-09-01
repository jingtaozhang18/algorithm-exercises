// https://leetcode-cn.com/problems/max-area-of-island/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int bfs(int i, int j, vector<vector<int>>& color) {
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    queue<pair<int, int>> que;
    que.emplace(i, j);
    int ans = 0, k, x, y, m = color.size(), n = color[0].size();
    color[i][j] = 2;
    while (que.size()) {
      i = que.front().first;
      j = que.front().second;
      que.pop();
      ++ans;
      for (k = 0; k < 4; ++k) {
        x = i + dir[k][0];
        y = j + dir[k][1];
        if (x >= 0 && x < m && y >= 0 && y < n) {
          if (color[x][y] == 1) {
            color[x][y] = 2;  // 被发现了
            que.emplace(x, y);
          }
        }
      }
      color[i][j] = 3;
    }
    return ans;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0, i, j;
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ans = max(ans, bfs(i, j, grid));
        }
      }
    }
    return ans;
  }
};