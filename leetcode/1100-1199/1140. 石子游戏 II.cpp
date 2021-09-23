// https://leetcode-cn.com/problems/stone-game-ii/
#include <bits/stdc++.h>
using namespace std;

unsigned long long generateKey(int x, int y) {
  return ((unsigned long long)x << 32) | (unsigned long long)y;
}

pair<int, int> releaseKey(unsigned long long key) {
  int b = key & 0x00000000ffffffff;
  int a = key >> 32;
  return make_pair(a, b);
}

class Solution {
 public:
  unordered_map<unsigned long long, int> mem;
  int calc(vector<int>& piles, vector<int>& backsum, int index,
           int m) {  // 是否是y
    unsigned long long key = generateKey(index, m);
    auto p = mem.find(key);
    if (p != mem.end()) return p->second;
    int ans = 0, i;
    for (i = 1; i <= m * 2 && index + i - 1 < piles.size(); ++i) {
      ans =
          max(ans, backsum[index] - calc(piles, backsum, index + i, max(m, i)));
    }
    return mem[key] = ans;
  }
  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<int> backsum(n + 1, 0);
    int i;
    for (i = piles.size() - 1; i >= 0; --i)
      backsum[i] = backsum[i + 1] + piles[i];
    return calc(piles, backsum, 0, 1);
  }
};
