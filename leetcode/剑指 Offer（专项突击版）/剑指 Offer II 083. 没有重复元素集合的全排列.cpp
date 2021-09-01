// https://leetcode-cn.com/problems/VvJkup/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> ans;
  vector<int> path;
  void calc(int i) {
    if (i == path.size()) ans.push_back(path);
    for (int j = i; j < path.size(); ++j) {
      swap(path[i], path[j]);
      calc(i + 1);
      swap(path[i], path[j]);
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    path = move(nums);
    calc(0);
    return ans;
  }
};