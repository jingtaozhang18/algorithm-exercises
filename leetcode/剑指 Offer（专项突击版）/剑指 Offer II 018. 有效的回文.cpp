// https://leetcode-cn.com/problems/XltzEq/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  inline bool valid(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
  }
  bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      while (left < right && !valid(s[left])) ++left;
      while (left < right && !valid(s[right])) --right;
      if (s[left] >= 'A' && s[left] <= 'Z') s[left] -= ('A' - 'a');
      if (s[right] >= 'A' && s[right] <= 'Z') s[right] -= ('A' - 'a');
      if (s[left] != s[right]) return false;
      ++left, --right;
    }
    return true;
  }
};
