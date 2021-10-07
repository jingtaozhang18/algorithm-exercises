// https://leetcode-cn.com/problems/stone-game-iv/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool winnerSquareGame(int n) {
    bool dp[n + 1];
    int i, x;
    dp[0] = false;
    for (i = 1; i <= n; ++i) {
      dp[i] = false;
      for (x = 1; x * x <= i; ++x) {
        if (dp[i - x * x] == false) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};