// https://leetcode-cn.com/problems/xx4gT2/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> que;
    for (auto& e : nums) {
      que.push(e);
      if (que.size() > k) {
        que.pop();
      }
    }
    return que.top();
  }
};