// https://leetcode-cn.com/problems/WGki4K/
#include <bits/stdc++.h>
using namespace std;

// ab 00 -> 01 -> 10 -> 00
// b= ~a&~b&e | ~a&b&~e
// a= ~a&b&e | a&~b&~e

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int a = 0, b = 0, x, y;
    for (auto& e : nums) {
      y = ~a & ~b & e | ~a & b & ~e;
      x = ~a & b & e | a & ~b & ~e;
      a = x, b = y;
    }
    return b;
  }
};