// https://leetcode-cn.com/problems/jJ0w9p/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    int left = 0, right = x;
    long long mid, y;
    while (left <= right) {
      mid = left + (right - left) / 2;
      y = mid * mid;
      if (y == x)
        return mid;
      else if (y > x)
        right = mid - 1;
      else
        left = mid + 1;
    }
    return right;
  }
};