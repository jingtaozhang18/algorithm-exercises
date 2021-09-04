// https://leetcode-cn.com/problems/count-primes/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    if (n == 0) return 0;
    bool arr[n];
    int i = 0, x, ans = 0;
    for (i = 2; i < n; ++i) arr[i] = true;  // 默认都是
    for (i = 2; i * 2 < n; ++i) {
      x = i + i;
      while (x < n) {
        arr[x] = false;
        x += i;
      }
    }
    for (i = 2; i < n; ++i) {
      if (arr[i]) ++ans;
    }
    return ans;
  }
};
