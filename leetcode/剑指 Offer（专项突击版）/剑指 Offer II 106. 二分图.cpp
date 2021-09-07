// https://leetcode-cn.com/problems/vEAB3K/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int m = graph.size(), i, j, x;
    short color[m];
    memset(color, 0, sizeof color);
    queue<int> que;
    for (i = 0; i < m; ++i) {
      if (!color[i]) {
        que.push(i);
        color[i] = 1;
        while (que.size()) {
          j = que.front();
          que.pop();
          if (color[j] == 1)
            x = 2;
          else
            x = 1;
          for (auto& e : graph[j]) {
            if (color[e] == 0) {
              color[e] = x;
              que.push(e);
            } else if (color[e] == x)
              ;
            else {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};