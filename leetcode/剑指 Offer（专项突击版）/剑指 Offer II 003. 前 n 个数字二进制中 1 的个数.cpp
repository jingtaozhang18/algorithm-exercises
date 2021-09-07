// https://leetcode-cn.com/problems/w3tCBm/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calc(int x) {
    int ans = 0;
    while (x) {
      ++ans;
      x = x & (x - 1);
    }
    return ans;
  }
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; ++i) {
      ans[i] = calc(i);
    }
    return ans;
  }
};