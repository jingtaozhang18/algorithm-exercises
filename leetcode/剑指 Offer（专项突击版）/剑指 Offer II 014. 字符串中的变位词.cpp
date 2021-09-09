// https://leetcode-cn.com/problems/MPnaiL/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int left = 0, right = 0, diff = 0;
    unordered_map<char, int> mp;
    for (char &c : s1) mp[c]++, ++diff;
    while (right < s2.size()) {
      if (mp[s2[right]] <= 0)
        ++diff;
      else
        --diff;
      --mp[s2[right++]];
      while (left < right && mp[s2[left]] < 0) ++mp[s2[left++]], --diff;
      if (diff == 0) return true;
    }
    return false;
  }
};
