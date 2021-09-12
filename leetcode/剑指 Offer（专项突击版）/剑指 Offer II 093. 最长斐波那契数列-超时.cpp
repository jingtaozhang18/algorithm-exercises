// https://leetcode-cn.com/problems/Q91FMA/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size(), i, j, count;
    unordered_set<unsigned long long> st;  // 记录开始的长度
    int ans = 0;
    auto toKey = [](int a, int b) -> unsigned long long {
      return (((unsigned long long)a) << 32) | ((unsigned long long)b);
    };
    auto toValue = [](unsigned long long key) -> pair<int, int> {
      return make_pair(key >> 32, (key << 32) >> 32);
    };
    auto preF = [](int a, int b) -> pair<int, int> {
      return make_pair(b - a, a);
    };
    auto posF = [](int a, int b) -> pair<int, int> {
      return make_pair(b, a + b);
    };
    for (i = 0; i < n; ++i)
      for (j = i + 1; j < n; ++j) {
        st.insert(toKey(arr[i], arr[j]));
      }
    for (auto& p : st) {
      auto [x, y] = toValue(p);
      auto pv = preF(x, y);
      if (st.find(toKey(pv.first, pv.second)) == st.end()) {
        pv = posF(x, y);
        count = 2;
        while (st.find(toKey(pv.first, pv.second)) != st.end()) {
          ++count;
          pv = posF(pv.first, pv.second);
        }
        ans = max(count, ans);
      }
    }
    if (ans >= 3)
      return ans;
    else
      return 0;
  }
};
