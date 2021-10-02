// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> ans;
    if (k == 0) return ans;
    int i;
    priority_queue<int, vector<int>, less<int>> que;
    for (i = 0; i < arr.size(); ++i) {
      if (que.size() < k)
        que.push(arr[i]);
      else if (que.top() > arr[i]) {
        que.pop();
        que.push(arr[i]);
      }
    }
    while (!que.empty()) {
      ans.push_back(que.top());
      que.pop();
    }
    return ans;
  }
};

// 复习
class Solution_fx {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    priority_queue<int, vector<int>> que;
    for (auto& e : arr) {
      que.push(e);
      if (que.size() > k) {
        que.pop();
      }
    }
    vector<int> ans;
    while (que.size()) {
      ans.push_back(que.top());
      que.pop();
    }
    return ans;
  }
};