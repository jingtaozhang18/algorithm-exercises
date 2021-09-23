// https://leetcode-cn.com/problems/g5c51o/
#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  }
};

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (auto& e : nums) ++mp[e];
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
    for (auto& e : mp) {
      que.emplace(e.second, e.first);
      if (que.size() > k) que.pop();
    }
    while (que.size()) {
      ans.push_back(que.top().second);
      que.pop();
    }
    return ans;
  }
};
