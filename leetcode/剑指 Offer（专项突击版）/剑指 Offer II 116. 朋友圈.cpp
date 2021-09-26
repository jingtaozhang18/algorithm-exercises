// https://leetcode-cn.com/problems/bLyHh0/
#include <bits/stdc++.h>
using namespace std;

struct ui {
  vector<int> mem;
  ui(int n) {
    mem = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      mem[i] = i;
    }
  }
  int find(int x) {
    if (mem[x] == x) return x;
    return mem[x] = find(mem[x]);
  }
  void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) mem[x] = y;
  }
  int kind() {
    unordered_set<int> st;
    for (int i = 0; i < mem.size(); ++i) {
      st.insert(find(i));
    }
    return st.size();
  }
};

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int m = isConnected.size(), i, j;
    ui u(m);
    for (i = 0; i < m; ++i) {
      for (j = 0; j < m; ++j) {
        if (isConnected[i][j] == 1) u.join(i, j);
      }
    }
    return u.kind();
  }
};