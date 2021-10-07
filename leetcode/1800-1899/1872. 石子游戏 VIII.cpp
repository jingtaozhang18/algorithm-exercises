// https://leetcode-cn.com/problems/stone-game-viii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int stoneGameVIII(vector<int>& stones) {
    vector<long long> acc;
    long long x = 0;
    int m = stones.size(), i;
    for (auto& e : stones) {
      x += e;
      acc.push_back(x);
    }
    vector<long long> dp(m);
    dp[m - 1] = acc[m - 1];
    for (i = m - 2; i > 0; --i) {
      dp[i] = max(dp[i + 1], acc[i] - dp[i + 1]);
    }
    return dp[1];
  }
};
