// https://leetcode-cn.com/problems/xoh6Oh/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long calc(long long a, long long b) {
    if (a < b) return 0;
    long long count = 1, bb = b;
    while (bb + bb < a) {
      count = count + count;
      bb = bb + bb;
    }
    return count + calc(a - bb, b);
  }
  int divide(int a, int b) {
    if (b == 1) return a;
    if (b == -1) return a == INT_MIN ? INT_MAX : -a;
    bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
    a = abs(a), b = abs(b);
    return sign ? calc(a, b) : -calc(a, b);
  }
};