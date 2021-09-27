// https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first + a.second < b.first + b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(
        cmp);
    int i, j, m = nums1.size(), n = nums2.size();
    for (i = 0; i < min(k, m); ++i) {
      for (j = 0; j < min(k, n); ++j) {
        que.emplace(nums1[i], nums2[j]);
        if (que.size() > k) que.pop();
      }
    }
    k = que.size();
    vector<vector<int>> ans(que.size());
    while (que.size()) {
      ans[--k] = {que.top().first, que.top().second};
      que.pop();
    }
    return ans;
  }
};
