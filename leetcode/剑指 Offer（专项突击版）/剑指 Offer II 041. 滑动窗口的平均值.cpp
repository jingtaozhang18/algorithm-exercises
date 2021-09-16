// https://leetcode-cn.com/problems/qIsx9U/
#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
 public:
  queue<int> que;
  int sum = 0;
  int size;
  MovingAverage(int size) { this->size = size; }

  double next(int val) {
    que.push(val);
    sum += val;
    if (que.size() > this->size) {
      sum -= que.front();
      que.pop();
    }
    return (double)sum / que.size();
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */