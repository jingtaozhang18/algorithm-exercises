// https://leetcode-cn.com/problems/0H97ZC/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> mp;
    int i;
    for (i = 0; i < arr2.size(); ++i) mp[arr2[i]] = i;
    auto cmp = [&](const int x, const int y) {
      auto p = mp.find(x);
      auto q = mp.find(y);
      if (p == mp.end() && q == mp.end()) {
        return x < y;
      } else if (p == mp.end()) {
        return false;
      } else if (q == mp.end()) {
        return true;
      } else
        return p->second < q->second;
    };
    sort(arr1.begin(), arr1.end(), cmp);
    return arr1;
  }
};
