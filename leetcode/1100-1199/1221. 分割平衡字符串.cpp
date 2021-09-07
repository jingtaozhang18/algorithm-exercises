// https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int balancedStringSplit(string s) {
    int balance = 0, ans = 0;
    for (auto& c : s) {
      if (c == 'L')
        ++balance;
      else
        --balance;
      if (balance == 0) ++ans;
    }
    return ans;
  }
};