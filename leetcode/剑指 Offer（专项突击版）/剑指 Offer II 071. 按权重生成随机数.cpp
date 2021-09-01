// https://leetcode-cn.com/problems/cuyjEf/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> acc;
  Solution(vector<int>& w) {
    acc.push_back(0);
    for (auto& e : w) {
      acc.push_back(acc.back() + e);
    }
  }

  int pickIndex() {
    int left = 0, right = acc.size() - 1, mid, x = rand() % acc.back();
    while (left <= right) {
      mid = (left + right) / 2;
      if (acc[mid] == x)
        return mid;
      else if (acc[mid] < x)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return right;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */