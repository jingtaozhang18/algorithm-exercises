// https://leetcode-cn.com/problems/NUPfPr/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canPartition(vector<int> &nums) {
    int acc = 0, i, n = nums.size(), m;
    for (auto &num : nums) acc += num;
    if (acc % 2) return false;
    m = acc / 2;
    bool dp[m + 1];
    queue<int> que;
    for (i = 0; i <= m; ++i) dp[i] = false;
    dp[0] = true;
    for (auto &num : nums) {
      for (i = 0; i + num <= m; ++i) {
        if (dp[i]) que.push(i + num);
      }
      while (que.size()) {
        dp[que.front()] = true;
        que.pop();
      }
    }
    return dp[m];
  }
};