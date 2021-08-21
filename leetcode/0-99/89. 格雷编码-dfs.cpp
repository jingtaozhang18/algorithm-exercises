// https://leetcode-cn.com/problems/gray-code/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void dfs(int val, unordered_set<int>& st, int n, vector<int>& ans) {
    for (int i = 0; i < n; ++i) {
      int x = val ^ (1 << i);
      if (st.find(x) == st.end()) {
        st.insert(x);
        ans.push_back(x);
        dfs(x, st, n, ans);
        return;
      }
    }
  }
  vector<int> grayCode(int n) {
    unordered_set<int> st;
    vector<int> ans;
    ans.push_back(0);
    st.insert(0);
    dfs(0, st, n, ans);
    return ans;
  }
};