// https://leetcode-cn.com/problems/random-pick-index/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int>::iterator start, end;
  Solution(vector<int>& nums) {
    start = nums.begin();
    end = nums.end();
  }

  int pick(int target) {
    vector<int>::iterator t = start;
    int i = 0, pos = 1, pool;
    while (t != end) {
      if (*t == target) {
        if (rand() % pos == 0) pool = i;
        ++pos;
      }
      ++i, ++t;
    }
    return pool;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */