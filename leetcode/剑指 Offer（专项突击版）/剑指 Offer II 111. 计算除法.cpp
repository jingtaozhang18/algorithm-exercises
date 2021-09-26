// https://leetcode-cn.com/problems/vlzXQL/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> mem;
    int i = 0;
    for (auto& p : equations) {
      mem[p[0]].push_back(make_pair(p[1], values[i]));
      mem[p[1]].push_back(make_pair(p[0], 1 / values[i++]));
    }
    queue<pair<string, double>> que;
    unordered_set<string> st;
    vector<double> ans;
    bool flag;
    double y;
    for (auto& p : queries) {
      if (mem.find(p[0]) == mem.end() || mem.find(p[1]) == mem.end()) {
        ans.push_back(-1.0);
        continue;
      }
      while (que.size()) que.pop();
      st.clear();
      que.emplace(p[0], 1);
      st.insert(p[0]);
      y = -1.0;
      while (que.size()) {
        auto [i, x] = que.front();
        que.pop();
        flag = false;
        for (auto& e : mem[i]) {
          if (e.first == p[1]) {
            y = x * e.second;
            flag = true;
            break;
          }
          if (st.find(e.first) == st.end()) {
            que.emplace(e.first, x * e.second);
            st.insert(e.first);
          }
        }
        if (flag) break;
      }
      ans.push_back(y);
    }
    return ans;
  }
};