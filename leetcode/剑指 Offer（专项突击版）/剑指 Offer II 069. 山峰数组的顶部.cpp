// https://leetcode-cn.com/problems/B1IidL/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int i, n = arr.size();
    for (i = 1; i < n - 1; ++i) {
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) return i;
    }
    return arr[0] > arr[1] ? 0 : i;
  }
};