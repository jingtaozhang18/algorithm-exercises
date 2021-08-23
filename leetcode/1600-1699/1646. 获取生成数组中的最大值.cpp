// https://leetcode-cn.com/problems/get-maximum-in-generated-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int getMaximumGenerated(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<int> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    int i = 2;
    for (; i <= n; ++i) {
      if (i % 2)
        arr[i] = arr[i / 2] + arr[i / 2 + 1];
      else
        arr[i] = arr[i / 2];
    }
    return *max_element(arr.begin(), arr.end());
  }
};