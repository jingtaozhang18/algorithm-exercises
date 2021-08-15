// https://leetcode-cn.com/problems/last-day-where-you-can-still-cross/
#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int latestDayToCross(int row, int col, vector<vector<int> >& cells) {
    bool arr[row][col];
    int dir[][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    int i, j, k, m = cells.size(), left = 0, right = m - 1, center, x, y;
    bool flag;
    queue<pair<int, int> > que;
    while (left <= right) {
      center = (left + right) / 2;
      for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j) arr[i][j] = true;
      for (k = 0; k <= center; ++k)
        arr[cells[k][0] - 1][cells[k][1] - 1] = false;
      flag = false;
      while (que.size()) que.pop();
      for (j = 0; j < col; ++j)
        if (arr[row - 1][j]) {
          que.push(make_pair(row - 1, j));  // 可以出发的地方
          arr[row - 1][j] = false;
        }
      while (que.size()) {
        i = que.front().first, j = que.front().second;
        que.pop();
        for (k = 0; k < 4; ++k) {
          x = i + dir[k][0], y = j + dir[k][1];
          if (x >= 0 && x < row && y >= 0 && y < col) {
            if (arr[x][y]) {
              que.push(make_pair(x, y));
              arr[x][y] = false;
              if (x == 0) {
                flag = true;
                break;
              }
            }
          }
        }
      }
      if (flag) {
        left = center + 1;
      } else {
        right = center - 1;
      }
    }
    return left;
  }
};