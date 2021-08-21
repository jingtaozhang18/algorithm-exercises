// https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  inline void jcalc(string &s, int i, int j) {
    while (i < j) swap(s[i++], s[j--]);
  }
  string reverseWords(string s) {
    int i, j = 0, m = s.size();
    for (i = 0; i <= m; ++i) {
      if (i == m || s[i] == ' ') {
        jcalc(s, j, i - 1);
        j = i + 1;
      }
    }
    return s;
  }
};