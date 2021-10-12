// https://leetcode-cn.com/problems/remove-boxes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeBoxes(vector<int>& boxes) {
    vector<pair<int, int>> arr;
    int i, j, d, k, x;
    for (i = j = 0;i <= boxes.size();++i) {
      if (i == boxes.size() || (i && boxes[i - 1] != boxes[i])) {
        arr.emplace_back(boxes[j], i - j);
        j = i;
      }
    }
    int m = arr.size();
    int dp[m][m];
    memset(dp, 0, sizeof(dp));
    for (d = 0;d < m;++d) {
      for (i = 0;i < m - d;++i) {
        j = i + d;
        for (k = i;k <= j;++k) {
          if (k == i) {
            x = pow(arr[k].second, 2);
            if (i < j) x += dp[i + 1][j];
            dp[i][j] = max(dp[i][j], x);
          }
          else if (k == j) {
            x = pow(arr[k].second, 2);
            if (i < j) x += dp[i][j - 1];
            dp[i][j] = max(dp[i][j], x);
          }
          else {
            if (k - 1 >= i && k + 1 <= j && arr[k - 1].first == arr[k + 1].first) { // 可以合并
              x = 0;
              if (i < k - 1) x += dp[i][k - 2];
              if (k + 1 < j) x += dp[k + 2][j];
              x += pow(arr[k].second, 2);
              x += pow(arr[k - 1].second + arr[k + 1].second, 2);
              dp[i][j] = max(dp[i][j], x);
            }
            else {
              x = 0;
              if (i < k) x += dp[i][k - 1];
              if (k < j) x += dp[k + 1][j];
              x += pow(arr[k].second, 2);
              dp[i][j] = max(dp[i][j], x);
            }
          }
        }
      }
    }
    return dp[0][m - 1];
  }
};