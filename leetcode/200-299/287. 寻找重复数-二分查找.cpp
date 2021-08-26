// https://leetcode-cn.com/problems/find-the-duplicate-number/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int left = 1, right = n, mid, cnt;
    while (left <= right) {
      mid = (left + right) >> 1;
      cnt = 0;
      for (auto& x : nums) {
        cnt += x <= mid;
      }
      if (cnt <= mid) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
};

// 此外还有位数的方法、快慢链表法