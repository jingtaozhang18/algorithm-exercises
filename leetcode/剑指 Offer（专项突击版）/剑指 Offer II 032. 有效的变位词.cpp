// https://leetcode-cn.com/problems/dKk3P7/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s == t) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};