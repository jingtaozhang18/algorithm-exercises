// https://leetcode-cn.com/problems/RQku0D/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool calc(string &s, int i, int j) {
    while (i < j && s[i] == s[j]) ++i, --j;
    if (i < j) return false;
    return true;
  }
  bool validPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (s[i] == s[j]) {
        ++i, --j;
      } else {
        return calc(s, i + 1, j) || calc(s, i, j - 1);
      }
    }
    return true;
  }
};