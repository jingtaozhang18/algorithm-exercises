// https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findIntegers(int n) {
    unsigned int x = 0;
    int ans = 0;
    while (x <= n) {
      if (((x >> 1) & x) == 0) ++ans;
      ++x;
    }
    return ans;
  }
};