// https://leetcode-cn.com/problems/WhsWhI/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int i, m = nums.size(), ans = 0, k;
    for (auto& e : nums) {
      // 重点：只从一个连续序列最开始的位置开始查找，而不是任意位置开始查找
      if (st.find(e - 1) != st.end()) continue;
      for (k = 1, i = e + 1; st.find(i) != st.end(); ++i, ++k)
        ;
      ans = max(ans, k);
    }
    return ans;
  }
};