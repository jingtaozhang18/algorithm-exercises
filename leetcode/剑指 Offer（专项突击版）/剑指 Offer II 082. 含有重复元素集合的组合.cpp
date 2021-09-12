// https://leetcode-cn.com/problems/4sjJUc/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void jgo(vector<int>& candidates, vector<int>& path, set<vector<int>>& ans,
           int sum, int index, int target) {
    if (index == candidates.size()) {
      if (sum == target) {
        vector<int> t(path);
        sort(t.begin(), t.end()), ans.insert(t);
      }
      return;
    }
    if (sum > target) return;
    jgo(candidates, path, ans, sum, index + 1, target);
    path.push_back(candidates[index]);
    jgo(candidates, path, ans, sum + candidates[index], index + 1, target);
    path.pop_back();
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    set<vector<int>> ret;
    vector<int> path;
    jgo(candidates, path, ret, 0, 0, target);
    for (auto p : ret) {
      ans.push_back(p);
    }
    return ans;
  }
};