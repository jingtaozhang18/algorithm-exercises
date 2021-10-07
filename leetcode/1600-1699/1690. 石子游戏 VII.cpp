// https://leetcode-cn.com/problems/stone-game-vii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int stoneGameVII(vector<int>& stones) {
    int m = stones.size(), i, j, k;
    int dp[m][m];  // 先手和后手之间的差距
    vector<int> acc;
    acc.push_back(0);
    for (auto& e : stones) acc.push_back(e + acc.back());
    for (k = 0; k < m; ++k) {
      for (i = 0; i < m - k; ++i) {
        j = i + k;
        if (k == 0)
          dp[i][j] = 0;  // 只剩下一个元素
        else {
          dp[i][j] = max(acc[j + 1] - acc[i + 1] - dp[i + 1][j],
                         acc[j] - acc[i] - dp[i][j - 1]);
        }
      }
    }
    return dp[0][m - 1];
  }
};