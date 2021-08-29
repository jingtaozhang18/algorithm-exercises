// https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    vector<int> acc;
    acc.push_back(0);
    for (auto& e : arr) acc.push_back(acc.back() + e);
    int ans = 0, k = 1, n = arr.size(), i;
    for (k = 1; k <= n; k += 2) {
      for (i = 0; i + k <= n; ++i) {
        ans += (acc[i + k] - acc[i]);
      }
    }
    return ans;
  }
};