// https://leetcode-cn.com/problems/stone-game-ix/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool stoneGameIX(vector<int>& stones) {
    int s[3] = {0, 0, 0};
    for (int i : stones) ++s[i % 3];
    if (s[0] % 2 == 0) return s[1] != 0 && s[2] != 0;
    return s[2] > s[1] + 2 || s[1] > s[2] + 2;
  }
};