// https://leetcode-cn.com/problems/QA2IGt/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> aff;
    vector<int> degree(numCourses, 0);
    vector<int> ans;
    int i, x;
    for (auto& p : prerequisites) {
      aff[p[1]].push_back(p[0]);  // 修完p[1],就可以为p[0]扫清一个障碍了
      degree[p[0]]++;
    }
    queue<int> que;
    for (i = 0; i < numCourses; ++i) {
      if (degree[i] == 0) {
        que.push(i);
      }
    }
    while (que.size()) {
      x = que.front();
      que.pop();
      ans.push_back(x);
      for (auto p : aff[x]) {
        degree[p]--;
        if (degree[p] == 0) {
          que.push(p);
        }
      }
    }
    return ans.size() < numCourses ? vector<int>(0) : ans;
  }
};