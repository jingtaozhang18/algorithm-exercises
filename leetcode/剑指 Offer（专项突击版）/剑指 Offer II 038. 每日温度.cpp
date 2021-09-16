// https://leetcode-cn.com/problems/iIQa4I/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> sta;  // index
    int i, n = temperatures.size();
    vector<int> ans(n);
    for (i = 0; i < n; ++i) {
      while (sta.size() && temperatures[sta.top()] < temperatures[i]) {
        ans[sta.top()] = i - sta.top();
        sta.pop();
      }
      sta.push(i);
    }
    while (sta.size()) {
      ans[sta.top()] = 0;
      sta.pop();
    }
    return ans;
  }
};
