// https://leetcode-cn.com/problems/XagZNi/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> sta;
    bool none;
    int i, n = asteroids.size();
    for (i = 0; i < n; ++i) {
      none = false;
      while (!none && sta.size() && (sta.top() > 0 && asteroids[i] < 0)) {
        if (abs(sta.top()) == abs(asteroids[i])) {
          sta.pop();
          none = true;
        } else if (abs(sta.top()) < abs(asteroids[i])) {
          sta.pop();
        } else {
          none = true;
        }
      }
      if (!none) sta.push(asteroids[i]);
    }
    vector<int> ans(sta.size());
    i = sta.size() - 1;
    while (i >= 0) {
      ans[i--] = sta.top();
      sta.pop();
    }
    return ans;
  }
};