// https://leetcode-cn.com/problems/third-maximum-number/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> que;
    unordered_set<int> st;
    for (auto& e : nums) {
      if (st.count(e)) continue;
      que.push(e);
      st.insert(e);
      if (que.size() > 3) {
        st.erase(que.top());
        que.pop();
      }
    }
    int ans;
    if (que.size() == 3)
      ans = que.top();
    else {
      for (; que.size(); que.pop()) ans = que.top();
    }
    return ans;
  }
};