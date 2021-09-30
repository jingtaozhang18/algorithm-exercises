// https://leetcode-cn.com/problems/rectangle-area/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    int yh = min(ay2, by2);
    int yl = max(ay1, by1);
    int xl = max(ax1, bx1);
    int xr = min(ax2, bx2);
    int sum = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
    if (yl < yh && xl < xr) {
      return sum - (xr - xl) * (yh - yl);
    }
    return sum;
  }
};