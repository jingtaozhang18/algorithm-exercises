// https://leetcode-cn.com/problems/random-point-in-non-overlapping-rectangles/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>>* rects;
  Solution(vector<vector<int>>& rects) { this->rects = &rects; }

  vector<int> pick() {
    int sum = 0, cur;
    vector<int>* ans;
    for (auto p = rects->begin(); p != rects->end(); ++p) {
      cur = ((*p)[2] - (*p)[0] + 1) * ((*p)[3] - (*p)[1] + 1);
      sum += cur;
      if (rand() % sum < cur) ans = &(*p);
    }
    int x1 = (*ans)[0], x2 = (*ans)[2], y1 = (*ans)[1], y2 = (*ans)[3];
    int x = x1 + rand() % (x2 - x1 + 1);
    int y = y1 + rand() % (y2 - y1 + 1);
    return {x, y};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */