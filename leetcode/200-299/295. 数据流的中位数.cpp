// https://leetcode-cn.com/problems/find-median-from-data-stream/
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
 public:
  priority_queue<int, vector<int>, less<int>> left;
  priority_queue<int, vector<int>, greater<int>> right;
  MedianFinder() {}

  void addNum(int num) {
    if (left.size() == 0) {
      left.push(num);
    } else if (num > left.top()) {
      right.push(num);
    } else {
      left.push(num);
    }
    while (left.size() > right.size() + 1) {
      right.push(left.top());
      left.pop();
    }
    while (right.size() > left.size()) {
      left.push(right.top());
      right.pop();
    }
  }

  double findMedian() {
    if (left.size() == right.size()) {
      return ((double)left.top() + (double)right.top()) / 2;
    } else {
      return left.top();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */