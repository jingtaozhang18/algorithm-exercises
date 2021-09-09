// https://leetcode-cn.com/problems/wtcaE1/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int left = 0, right = 0, ans = 0;
    while (right < s.size()) {
      if (++mp[s[right]] > 1) {
        while (s[left] != s[right]) --mp[s[left++]];
        --mp[s[left++]];
      }
      ++right;
      ans = max(ans, right - left);  // 先加right了
    }
    return ans;
  }
};
