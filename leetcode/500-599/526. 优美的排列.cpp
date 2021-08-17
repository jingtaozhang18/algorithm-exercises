// https://leetcode-cn.com/problems/beautiful-arrangement/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<bool> color;
  int ans;
  void calc(int i, int n) {
    if (i == n) {
      ans++;
    }
    for (int j = 1; j <= n; ++j) {
      if (color[j]) {
        if ((i + 1) % j == 0 || j % (i + 1) == 0) {
          color[j] = false;
          calc(i + 1, n);
          color[j] = true;
        }
      }
    }
  }
  int countArrangement(int n) {
    color = vector<bool>(n + 1, true);
    ans = 0;
    calc(0, n);
    return ans;
  }
};