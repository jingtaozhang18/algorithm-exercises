// https://leetcode-cn.com/problems/Ygoe9J/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> path;

 public:
  void calc(int i, vector<tuple<int, int, int>> from[], set<vector<int>>& ans) {
    if (i == 0) {
      if (path.size()) {
        vector<int> pa(path);
        sort(pa.begin(), pa.end());
        ans.insert(pa);
      }
      return;
    };
    int j;
    for (auto& e : from[i]) {
      auto& [pre_i, ele, times] = e;
      if (path.size() && path.back() < ele) continue;
      path.push_back(ele);
      for (j = 0; j < times; ++j) {
        calc(pre_i, from, ans);
      }
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int arr[target + 1];
    vector<tuple<int, int, int>> from[target + 1];  // from
    int i, j = 0;
    for (i = 1; i <= target; ++i) arr[i] = 0;
    arr[0] = 1;
    sort(candidates.begin(), candidates.end());
    for (auto& e : candidates) {
      for (i = 0; i + e <= target; ++i) {
        if (arr[i]) {
          arr[i + e] += arr[i];
          from[i + e].emplace_back(i, e, arr[i]);
        }
      }
      ++j;
    }
    set<vector<int>> ans;
    calc(target, from, ans);
    vector<vector<int>> res;
    for (auto& p : ans) res.push_back(p);
    return res;
  }
};