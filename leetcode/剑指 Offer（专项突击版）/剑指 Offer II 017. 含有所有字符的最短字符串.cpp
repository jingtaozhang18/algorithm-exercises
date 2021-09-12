// https://leetcode-cn.com/problems/M1oyTv/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    int m = s.size(), n = t.size(), ans_pos = -1, ans_val = INT_MAX, x;
    int diff = n;
    for (auto& e : t) mp[e]++;
    int left = 0, right = 0;
    while (right < m) {
      if (mp.find(s[right]) != mp.end()) {
        if (mp[s[right]]-- > 0) --diff;
      }
      if (!diff) {
        // 去掉左边没用的地方
        auto p = mp.find(s[left]);
        while (p == mp.end() || p->second < 0) {
          if (p != mp.end()) p->second++;
          p = mp.find(s[++left]);
        }
        x = right - left;
        if (x < ans_val) ans_val = x, ans_pos = right;
        mp[s[left++]]++;
        ++diff;
      }
      ++right;
    }
    if (ans_pos >= 0)
      return s.substr(ans_pos - ans_val, ans_val + 1);
    else
      return "";
  }
};