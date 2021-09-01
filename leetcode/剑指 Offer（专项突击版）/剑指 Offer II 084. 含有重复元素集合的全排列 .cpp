// https://leetcode-cn.com/problems/7p8L0Z/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> path;
  vector<vector<int>> ans;
  void calc(int i) {
    if (i == path.size()) {
      ans.push_back(path);
    }
    unordered_set<int> st;
    for (int j = i; j < path.size(); ++j) {
      if (st.find(path[j]) == st.end()) {
        st.insert(path[j]);
        swap(path[i], path[j]);
        calc(i + 1);
        swap(path[i], path[j]);
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    path = move(nums);
    calc(0);
    return ans;
  }
};