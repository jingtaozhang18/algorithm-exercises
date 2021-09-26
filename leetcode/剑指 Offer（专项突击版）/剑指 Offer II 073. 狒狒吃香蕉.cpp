// https://leetcode-cn.com/problems/nZZqjQ/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isOk(vector<int>& piles, int h, int k) {
    int acc = 0;
    for (auto& p : piles) {
      acc += p / k;
      if (p % k != 0) ++acc;
      if (acc > h) return false;
    }
    return acc <= h;
  }
  int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = 0, mid;
    for (auto& p : piles) right = max(right, p);
    while (left <= right) {
      mid = (left + right) / 2;
      if (isOk(piles, h, mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};