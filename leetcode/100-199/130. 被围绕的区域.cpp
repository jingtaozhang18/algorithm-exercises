// https://leetcode-cn.com/problems/surrounded-regions/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size(), i, j, k, flag = 2, x, y, a, b;
    vector<vector<int>> arr(m, vector<int>(n, 0)); // 0 没有处理，1发现，2已处理
    unordered_map<int, bool> mem; // 记录遍历的结果
    queue<pair<int, int>> que;
    int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
    for (i = 0;i < m;++i) {
      for (j = 0;j < n;++j) {
        if (board[i][j] == 'O') {
          if (arr[i][j] >= 2) {
            if (mem[arr[i][j]]) {
              board[i][j] = 'X';
            }
          }
          else {
            // bfs 遍历
            que.emplace(i, j);
            mem[flag] = true; // 默认被包围
            while (que.size()) {
              a = que.front().first;
              b = que.front().second;
              que.pop();
              for (k = 0;k < 4;++k) {
                x = a + dir[k][0];
                y = b + dir[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                  if (board[x][y] == 'O' && arr[x][y] == 0) {
                    arr[x][y] = 1;
                    que.emplace(x, y);
                  }
                }
                else {
                  mem[flag] = false;
                }
              }
              arr[a][b] = flag;
            }
            ++flag;
            if (mem[arr[i][j]]) {
              board[i][j] = 'X';
            }
          }
        }
      }
    }
  }
};