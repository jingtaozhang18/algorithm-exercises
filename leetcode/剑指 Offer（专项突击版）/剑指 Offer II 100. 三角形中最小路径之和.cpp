// https://leetcode-cn.com/problems/IlPe0q/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int i, j, x, ans = INT_MAX;
    if (triangle.size() == 1) return triangle[0][0];
    for (i = 1; i < triangle.size(); ++i) {
      for (j = 0; j < triangle[i].size(); ++j) {
        x = INT_MAX;
        if (j) x = min(x, triangle[i - 1][j - 1]);
        if (j < triangle[i].size() - 1) x = min(x, triangle[i - 1][j]);
        triangle[i][j] += x;
        if (i == triangle.size() - 1) {
          ans = min(ans, triangle[i][j]);
        }
      }
    }
    return ans;
  }
};