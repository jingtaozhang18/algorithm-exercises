// https://leetcode-cn.com/problems/ZL6zAn/
#include <bits/stdc++.h>
using namespace std;

struct un {
  vector<int> arr;
  un(int n) {
    arr = vector<int>(n);
    for (int i = 0; i < n; ++i) arr[i] = i;
  }
  int find(int i) {
    if (arr[i] == i) return i;
    return arr[i] = find(arr[i]);
  }
  void junion(int i, int j) {
    i = find(i);
    j = find(j);
    if (i != j) arr[i] = j;
  }
};
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int dir[2][2] = {1, 0, 0, 1}, m = grid.size(), n = grid[0].size(), i, j, x,
        y, k, ans = 0;
    un jun(m * n);
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          for (k = 0; k < 2; ++k) {
            x = i + dir[k][0];
            y = j + dir[k][1];
            if (x < m && y < n) {
              if (grid[x][y] == 1) {
                jun.junion(i * n + j, x * n + y);
              }
            }
          }
        }
      }
    }
    unordered_map<int, int> mp;
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          mp[jun.find(i * n + j)]++;
          ans = max(mp[jun.find(i * n + j)], ans);
        }
      }
    }
    return ans;
  }
};

// 还有bfs的思想，参考【695. 岛屿的最大面积】