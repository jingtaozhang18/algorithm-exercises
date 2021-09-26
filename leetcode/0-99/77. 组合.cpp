// https://leetcode-cn.com/problems/combinations/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> ans;

  void calc(vector<int>& path, int i, int n, int k) {
    if (path.size() == k) {
      ans.push_back(path);
      return;
    }
    if (i > n) return;
    if (n - i >= k - path.size()) calc(path, i + 1, n, k);
    path.push_back(i);
    calc(path, i + 1, n, k);
    path.pop_back();
  }
  vector<vector<int>> combine(int n, int k) {
    vector<int> path;
    calc(path, 1, n, k);
    return ans;
  }
};
