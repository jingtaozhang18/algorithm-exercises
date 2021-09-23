// https://leetcode-cn.com/problems/jBjn9C/
#include <bits/stdc++.h>
using namespace std;

class KthLargest {
 public:
  priority_queue<int, vector<int>, greater<int>> que;
  int k;
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    que = priority_queue<int, vector<int>, greater<int>>(nums.begin(),
                                                         nums.end());
    while (que.size() > k) que.pop();
  }

  int add(int val) {
    que.push(val);
    if (que.size() > k) que.pop();
    return que.top();
  }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */