// https://leetcode-cn.com/problems/bP4bmD/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> ans;
  vector<int> path;
  void dfs(int index, vector<vector<int>>& graph) {
    if (index == graph.size() - 1) {
      ans.push_back(path);
      return;
    }
    for (auto& x : graph[index]) {
      path.push_back(x);
      dfs(x, graph);
      path.pop_back();
    }
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    path.push_back(0);
    dfs(0, graph);
    return ans;
  }
};