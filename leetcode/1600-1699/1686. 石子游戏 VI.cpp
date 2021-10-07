// https://leetcode-cn.com/problems/stone-game-vi/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    vector<pair<int, int>> arr;
    int i, n = aliceValues.size();
    for (i = 0; i < n; ++i) {
      arr.emplace_back(aliceValues[i] + bobValues[i], i);
    }
    sort(arr.rbegin(), arr.rend());
    int sum1 = 0, sum2 = 0;
    for (i = 0; i < n; ++i) {
      if (i % 2 == 0)
        sum1 += aliceValues[arr[i].second];
      else
        sum2 += bobValues[arr[i].second];
    }
    if (sum1 > sum2) return 1;
    if (sum1 < sum2) return -1;
    return 0;
  }
};