// https://leetcode-cn.com/problems/reverse-only-letters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool is(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }
  string reverseOnlyLetters(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      while (i < j && !is(s[i])) ++i;
      while (i < j && !is(s[j])) --j;
      if (i < j) swap(s[i], s[j]);
      ++i, --j;
    }
    return s;
  }
};