// https://leetcode-cn.com/problems/7LpjUW/
#include <bits/stdc++.h>
using namespace std;

struct uion {
  vector<int> mem;
  uion(int n) {
    mem = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      mem[i] = i;
    }
  }
  int find(int x) {
    if (mem[x] == x) return x;
    return mem[x] = find(mem[x]);
  }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      mem[x] = y;
      return true;
    }
    return false;
  }
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int m = edges.size(), i;
    uion un(m);
    for (auto& edge : edges) {
      if (!un.join(edge[0] - 1, edge[1] - 1)) {
        return edge;
      }
    }
    return {};
  }
};
