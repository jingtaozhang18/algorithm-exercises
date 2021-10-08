// https://leetcode-cn.com/problems/dungeon-game/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon)
  {
    int m = dungeon.size(), n = dungeon[0].size();
    int i, j, t;
    for (i = m - 1; i >= 0; --i)
    {
      for (j = n - 1; j >= 0; --j)
      {
        if (i == m - 1 && j == n - 1)
        {
          // 错误点，最小应该是1
          dungeon[i][j] = max(1 - dungeon[i][j], 1);
          continue;
        }
        t = INT_MAX;
        // t+dp[i][j]>=dp[i+1][j]
        // 错误点：上述式子还需要保证出来的时候不死
        // 正确推导：t+dp[i][j]>=max(dp[i+1][j], 1)
        // 换种思路，是t+dp[i][j]>=dp[i+1][j]完成后，t=max(t, 1)
        if (i < m - 1)
        { // [i+1][j]
          // t=min(t, max(0, max(dungeon[i+1][j], 1)-dungeon[i][j]));
          t = min(t, dungeon[i + 1][j] - dungeon[i][j]);
        }
        if (j < n - 1)
        {
          // t=min(t, max(0, max(dungeon[i][j+1], 1)-dungeon[i][j]));
          t = min(t, dungeon[i][j + 1] - dungeon[i][j]);
        }
        dungeon[i][j] = max(1, t);
      }
    }
    // 错误点：只有一个格子还是血瓶的时候，需要保证来的时候是有血的
    return dungeon[0][0];
  }
};

// 复习
class Solution_fx
{
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon)
  {
    int m = dungeon.size(), n = dungeon[0].size(), i, j, x;
    int dp[m][n];
    for (i = m - 1; i >= 0; --i)
    {
      for (j = n - 1; j >= 0; --j)
      {
        x = INT_MAX; // 需要的最少血量
        if (i == m - 1 && j == n - 1)
          x = 1;
        if (i < m - 1)
          x = min(x, dp[i + 1][j]);
        if (j < n - 1)
          x = min(x, dp[i][j + 1]);
        dp[i][j] = max(1, x - dungeon[i][j]);
      }
    }
    return dp[0][0];
  }
};
