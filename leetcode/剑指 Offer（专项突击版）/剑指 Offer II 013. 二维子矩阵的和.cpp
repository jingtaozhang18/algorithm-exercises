// https://leetcode-cn.com/problems/O4NDxx/
#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
 public:
  vector<vector<int>> matrix;
  NumMatrix(vector<vector<int>>& mi) {
    matrix = move(mi);
    int i, j, m = matrix.size(), n = matrix[0].size();
    for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
        if (i) matrix[i][j] += matrix[i - 1][j];
        if (j) matrix[i][j] += matrix[i][j - 1];
        if (i && j) matrix[i][j] -= matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    sum += matrix[row2][col2];
    if (row1 && col1) sum += matrix[row1 - 1][col1 - 1];
    if (col1) sum -= matrix[row2][col1 - 1];
    if (row1) sum -= matrix[row1 - 1][col2];
    return sum;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */