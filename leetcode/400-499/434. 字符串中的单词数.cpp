// https://leetcode-cn.com/problems/number-of-segments-in-a-string/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countSegments(string s) {
    int sum = 0;
    bool flag = true;
    for (auto& c : s) {
      if (c != ' ') {
        if (flag) {
          ++sum;
          flag = false;
        }
      } else {
        flag = true;
      }
    }
    return sum;
  }
};