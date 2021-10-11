// https://leetcode-cn.com/problems/number-of-valid-subarrays/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int validSubarrays(vector<int>& nums) {
    stack<int> sta;
    int i, m = nums.size();
    int flagR[m];
    for (i = 0;i < m;++i) {
      while (sta.size() && nums[sta.top()] > nums[i]) {
        flagR[sta.top()] = i;
        sta.pop();
      }
      sta.push(i);
    }
    while (sta.size()) {
      flagR[sta.top()] = i;
      sta.pop();
    }
    int ans = 0;
    for (i = 0;i < m;++i) {
      ans += flagR[i] - i;
    }
    return ans;
  }
};