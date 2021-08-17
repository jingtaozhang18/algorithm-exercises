// https://leetcode-cn.com/problems/student-attendance-record-i/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool checkRecord(string s) {
    int a = 0, l = 0, i;
    for (i = 0; i < s.size(); ++i) {
      if (s[i] == 'A') a++;
      if (s[i] == 'L') {
        if (i && s[i] == 'L')
          ++l;
        else
          l = 1;
      } else {
        l = 0;
      }
      if (a >= 2) return false;
      if (l >= 3) return false;
    }
    return true;
  }
};