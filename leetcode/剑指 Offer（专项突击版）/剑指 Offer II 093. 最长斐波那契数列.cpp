// https://leetcode-cn.com/problems/Q91FMA/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size(), i, j, count, x, a, b, ans = 0;
    unordered_set<int> st(arr.begin(), arr.end());
    auto preV = [](int a, int b) -> int { return b - a; };
    auto posV = [](int a, int b) -> int { return b + a; };
    for (i = 0; i < n; ++i) {
      for (j = i + 1; j < n; ++j) {
        a = arr[i];
        b = arr[j];
        x = preV(a, b);
        if (x >= a || st.find(x) == st.end()) {  // 错误点
          count = 2;
          x = posV(a, b);
          //   cout<<a<<"\t"<<b<<"\t";
          while (st.find(x) != st.end()) {
            ++count;
            a = b;
            b = x;
            x = posV(a, b);
          }
          //   cout<<count<<"\n";
          ans = max(ans, count);
        }
      }
    }
    if (ans >= 3)
      return ans;
    else
      return 0;
  }
};
