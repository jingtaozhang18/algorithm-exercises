// https://leetcode-cn.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    long dis[n][n];
    int i, j, k, bk, ans;
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j) dis[i][j] = (i == j) ? 0 : INT_MAX;
    for (auto& e : edges) dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
    for (k = 0; k < n; ++k) {
      for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
          if (dis[i][j] > dis[i][k] + dis[k][j]) {
            dis[i][j] = dis[i][k] + dis[k][j];
          }
        }
      }
    }
    ans = bk = INT_MAX;
    for (i = 0; i < n; ++i) {
      k = 0;
      for (j = 0; j < n; ++j) {
        if (dis[i][j] <= distanceThreshold) {
          ++k;
        }
      }
      // cout<<i<<"\t"<<k<<endl;
      if (k <= bk) {
        bk = k;
        ans = i;
      }
    }
    return ans;
  }
};