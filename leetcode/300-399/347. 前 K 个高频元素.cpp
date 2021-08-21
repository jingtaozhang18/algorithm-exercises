// https://leetcode-cn.com/problems/top-k-frequent-elements/
#include <bits/stdc++.h>
using namespace std;

struct node {
  int key, ts;
  node(int key, int ts) : key(key), ts(ts) {}
  bool operator<(const node& other) const { return ts > other.ts; }
};

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (auto& e : nums) mp[e]++;
    priority_queue<node> que;
    for (auto& p : mp) {
      que.emplace(p.first, p.second);
      if (que.size() > k) que.pop();
    }
    vector<int> ans;
    while (que.size()) {
      ans.push_back(que.top().key);
      que.pop();
    }
    return ans;
  }
};