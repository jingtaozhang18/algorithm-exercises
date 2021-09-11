// https://leetcode-cn.com/problems/Ygoe9J/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> ans;

  void calc(int i, vector<int>& candidates, vector<int>& path, int target) {
    if (target < 0) return;  // 没有意义了
    if (target == 0) {
      ans.push_back(path);
      return;
    }                                    // 满足条件
    if (i == candidates.size()) return;  // 没得搞了
    int k = 1;
    calc(i + 1, candidates, path, target);  // 0个
    while (target - candidates[i] * k >= 0) {
      path.push_back(candidates[i]);
      calc(i + 1, candidates, path, target - candidates[i] * k);
      ++k;
    }
    while (--k) path.pop_back();
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    calc(0, candidates, path, target);
    return ans;
  }
};