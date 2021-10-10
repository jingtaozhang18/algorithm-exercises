// https://leetcode-cn.com/problems/arranging-coins/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int arrangeCoins(int n) {
    long long left = 0, right = 1e5, mid, nn = n;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (mid * (mid + 1) <= nn * 2) left = mid + 1;
      else right = mid - 1;
    }
    return right;
  }
};
