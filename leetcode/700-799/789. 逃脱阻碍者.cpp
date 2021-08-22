// https://leetcode-cn.com/problems/escape-the-ghosts/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  inline int jcalc(vector<int>& start, vector<int>& end) {
    return abs(start[0] - end[0]) + abs(start[1] - end[1]);
  }

  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    vector<int> start(2, 0);
    int distance = jcalc(start, target);
    for (auto& g : ghosts) {
      if (jcalc(g, target) <= distance) return false;
    }
    return true;
  }
};